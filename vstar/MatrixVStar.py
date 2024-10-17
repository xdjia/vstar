"""
V-Star with tables implemented as numpy arrays.
"""

import os
import pickle
import numpy as np
from itertools import combinations
from collections import defaultdict, deque
from typing import Callable, Literal, Union

import matplotlib.pyplot as plt
import vstar.Eval as Eval
import vstar.SampleStrings as SampleStrings

from .Colors import blue
from .RE import group_chars
from .Utils import pp, debug
from .Oracle import Oracle
from .Token import CE, Token, pp_ce
from .Tokenizer import Tokenizer, expand_tokens
from .Utils import remove_duplicates_keep_order
from .Utils import info, lowercase, uppercase, digits
from .Utils import path_to_result, art_call, art_retn
from .Automata import DFA, remove_unacceptable_states, run_dfa

from .Types import TOKEN, MOD_NT, ALTs, M_TERMINALs, GRAMMAR, IGRAMMAR, pp_alt, pp_cs, pp_cxt, pp_grammar, print_grammar


def print_matrix(module, cxt2i, matrix, Q: list[str],
                 cxts: list[tuple[str, str]], q2id):
    """ Print the matrix table. """

    info(f"M{module}\t" +
         "\t".join(f"({pp(cxt[0])},{pp(cxt[1])})" for cxt in cxts))

    for _, q in enumerate(Q):
        iq = q2id[q]
        pp_s = []
        for cxt in cxts:
            if matrix[iq, cxt2i[cxt]] == 1:
                pp_s.append("O")
            elif matrix[iq, cxt2i[cxt]] == -1:
                pp_s.append("X")
            else:
                pp_s.append("_")

        info(pp(q) + "\t" + "\t".join(pp_s))


def pp_token(token: TOKEN) -> str:
    """ pretty print tokens """

    match token:
        case str(s):
            return pp(s)
        case (c, (a, p, b)):
            return f"({pp(c)}, ({pp(a)},{pp(p)},{pp(b)}))"
        case _:
            raise ValueError(token)


def reduce_grammar(grammar: IGRAMMAR):
    """ 
    Remove redundant nonterminals, such as L that can only derive L. 
    """

    for i, rules in grammar.items():
        reachable_nt = [nt for nt in rules if "" in rules[nt]]

        new_reachable = True

        # NOTE - collect reachable nonterminals
        while new_reachable:
            new_reachable = False

            for nt in rules:
                if nt in reachable_nt:
                    continue

                for alt in rules[nt]:
                    match alt:
                        case (_, nt2):
                            if nt2 in reachable_nt:
                                new_reachable = True
                                reachable_nt.append(nt)
                                break
                        case (_, _, _, nt2):
                            if nt2 in reachable_nt:
                                new_reachable = True
                                reachable_nt.append(nt)
                                break

        # NOTE - remove unreachable rules
        for nt in rules:
            alts = []
            for alt in rules[nt]:
                match alt:
                    case "":
                        alts.append(alt)
                    case (_, nt2):
                        if nt2 in reachable_nt:
                            alts.append(alt)
                    case (_, _, _, nt2):
                        if nt2 in reachable_nt:
                            alts.append(alt)

            rules[nt] = alts

        grammar[i] = rules

    # NOTE - remove nonterminals that has no rule
    for rules in grammar.values():
        for nt in list(rules.keys()):
            if not rules[nt]:
                rules.pop(nt)
            # print_info(rules[i])

    # NOTE - remove unreachable modules

    nt0: MOD_NT = (0, 0)
    worklist: deque[tuple[int, int]] = deque([nt0])
    visited: set[MOD_NT] = set([nt0])

    while worklist:
        nt = worklist.popleft()

        rules = grammar[nt[0]]
        for _, alts in rules.items():
            for alt in alts:
                match alt:
                    case (_, (nt2, _)):
                        if nt2 not in visited:
                            worklist.append(nt2)
                            visited.add(nt2)
                    case (_, (nt1, _), _, (nt2, _)):
                        if nt1 not in visited:
                            worklist.append(nt1)
                            visited.add(nt1)
                        if nt2 not in visited:
                            worklist.append(nt2)
                            visited.add(nt2)

    for i in list(grammar.keys()):
        for nt in grammar[i]:
            if nt[0][1] == 0 and nt[0] not in visited:
                grammar.pop(i)
                break

    return grammar


def pp_mc(c: tuple[Token, str] | str):
    """ Pretty print token or str. """

    match c:
        case str(c):
            return pp(c)
        case (token, w):
            return pp(w)


class VPALearner:
    def __init__(self, oracle: Oracle,
                 cals: list[str],
                 rets: list[str],
                 plns: list[str],
                 cxtss: list[list[tuple[str, str]]],
                 tokenizer: Tokenizer) -> None:

        self.tokenizer = tokenizer

        self.n_classes = n_classes = len(cals) + 1

        self.grammar_name = oracle.name
        self.set_oracle(oracle)
        self.cals = cals
        self.rets = rets
        self.plns = plns
        self.cxtss = [[] for _ in range(n_classes)]

        self.Q2id: list[dict[str, int]] = [{} for _ in range(n_classes)]
        self.id2Q: list[dict[int, str]] = [{} for _ in range(n_classes)]
        self.CXT2id: list[dict[tuple[str, str], int]]
        self.CXT2id = [{} for _ in range(n_classes)]
        self.id2CXT: list[dict[int, tuple[str, str]]]
        self.id2CXT = [{} for _ in range(n_classes)]

        # NOTE - Alloc memory for the table.
        N_ROW, N_COL = 50000, 1000
        self.matrices = [np.zeros([N_ROW, N_COL], dtype=int)
                         for _ in range(n_classes)]
        self.Qs: list[list[str]] = [[] for _ in range(n_classes)]

        # NOTE - init chars and matched tokens
        m_terminals: list[TOKEN]
        m_terminals = [pln for pln in plns]

        for a, b in zip(cals, rets):
            assert (a + b, (a, "", b)) not in m_terminals
            m_terminals.append((a + b, (a, "", b)))

        self.m_terminals = m_terminals

        # NOTE - init using the first strings
        for i in range(n_classes):
            self.add_q2id(i, "")
            self.Qs[i].append("")

        for i in range(n_classes):
            for cxt in cxtss[i]:
                self.add_cxt(i, cxt)

        # NOTE - consolidated VPA
        self.module_q2p_ms: list[
            dict[tuple[str, str],
                 M_TERMINALs]]
        self.module_q2p_ms = []

        self.module_transitions: list[
            dict[tuple[str, str] | tuple[str, str, tuple[int, str, str]], str]]
        self.module_transitions = []

        self.acc_states = []

        self.history = []

        self.recall_dataset = ''

    def set_oracle(self, oracle):
        self.oracle: Callable[[str], bool] = lambda s: oracle(s)
        self._oracle = oracle

    def __getstate__(self):
        state = self.__dict__.copy()
        # NOTE - Replace the function with None or a placeholder
        #        that preserves type info
        if 'oracle' in state:
            state['oracle'] = None  # Or some placeholder
        if '_oracle' in state:
            state['_oracle'] = None  # Or some placeholder

        return state

    def __setstate__(self, state):
        self.__dict__.update(state)

    def dump_learner(self, folder='learner'):
        file_folder = os.path.join(path_to_result, folder)
        if not os.path.exists(file_folder):
            os.mkdir(file_folder)
        file_path = os.path.join(file_folder, f"{self.grammar_name}.pickle")
        with open(file_path, "wb") as f:
            pickle.dump(self, f)

        info(f"learner saved as {file_path}")

    def find_eq(self, str2id, matrix, Q, q2) -> str:
        for q in Q:
            if np.array_equal(matrix[str2id[q]], matrix[str2id[q2]]):
                return q

        raise ValueError(f"Equivalence class for q={pp(q2)} not found.")

    def i2prefix(self, index: int) -> str:
        return f"m{index}_"

    def vmatrix2mapping(self, cxt2id, matrix, chars, Q: list[str]):
        """ Convert matrix table to transitions. """

        mapping = {}

        for q in Q:
            for c in chars:
                qc = q + c
                eq = self.find_eq(cxt2id, matrix, Q, qc)
                mapping[(q, c)] = eq

        return mapping

    def break_counterexample(self, ce: CE
                             ) -> None | tuple[int, tuple[str, str, str], str]:
        """ 
        Break the potential counterexample ce to 
        (module, (left_cxt, right_cxt, inner_right_cxt), new representative).
        """

        stack: list[tuple[int, str, tuple[Token, str]]] = []
        state: str = ""
        module: int = 0

        Os = self.oracle(ce[0])
        debug(f"string {pp(ce[0])} is tokenized as {pp_ce(ce)}")

        for i, c in enumerate(ce[1]):

            if isinstance(c, tuple) and c[0].token_type == 'call':
                stack.append((module, state, c))
                module = c[0].module
                state = ""
            else:
                # NOTE - build right context string
                right_cxt: str = ""
                for c2 in ce[1][i + 1:]:
                    match c2:
                        case str(c2):
                            right_cxt += c2
                        case (_, w2):
                            right_cxt += w2
                        case _:
                            raise ValueError(c2)

                # NOTE - build new state and left context string
                if isinstance(c, tuple) and c[0].token_type == 'return':
                    module, prev_state, (call_token, _) = stack.pop()
                    a = call_token.repr
                    b = c[0].repr
                    qc = prev_state + a + state + b
                else:
                    assert isinstance(c, str)
                    qc = state + c

                left_cxt = ""
                for v in stack:
                    left_cxt += v[1] + v[2][1]

                if qc not in self.Q2id[module]:
                    info(f"M{module} q: {pp(state)} c: {pp_mc(c)} qc: {qc}")
                    info(self.Q2id[module][qc])
                    info(list(self.Q2id[module].keys()))
                    debug(self.print_mterminals())
                    self.print_Qs()
                    self._oracle.print_info()
                    raise ValueError

                assert qc in self.Q2id[module], qc

                eq_qc = self.find_eq(
                    self.Q2id[module], self.matrices[module], self.Qs[module], qc)

                # NOTE - Check discrepency
                debug(
                    f"({pp(state)},{pp_mc(c)}) -> " +
                    f"M{module} {pp(eq_qc)} ({pp(qc)}) " +
                    f"l={pp(left_cxt)} r={pp(right_cxt)}")

                if Os != self.oracle(left_cxt + eq_qc + right_cxt):
                    debug(f"Result: {Os} " + pp(left_cxt + eq_qc + right_cxt))
                    info(f"Broken at M{module} ({pp(left_cxt)}, {pp(qc)}, {
                         pp(right_cxt)})")

                    if stack:
                        inner_right_cxt = ""
                        for c2 in ce[1][i + 1:]:
                            match c2:
                                case str(c2):
                                    inner_right_cxt += c2
                                case _:
                                    break
                    else:
                        inner_right_cxt = right_cxt

                    return (module, (left_cxt, right_cxt, inner_right_cxt), qc)

                state = eq_qc

        assert not stack
        return None

    def add_q2id(self, module: int, s: str) -> int:
        """ Assign an integer ID to a string (i.e. a state/prefix) s. """

        q2id = self.Q2id[module]

        if s in q2id:
            return q2id[s]

        i_s = len(q2id)
        q2id[s] = i_s
        self.id2Q[module][i_s] = s

        return i_s

    def add_cxt2id(self, module: int, cxt: tuple[str, str]) -> int:
        """ Assign an integer ID to a context. """

        cxt2id = self.CXT2id[module]

        assert cxt not in cxt2id

        i_s = len(cxt2id)
        cxt2id[cxt] = i_s
        self.id2CXT[module][i_s] = cxt

        return i_s

    def update_matrix(self, module: int, cxt: tuple[str, str], q: str):
        """ Update the row q and column cxt in the matrix table. """

        iq = self.add_q2id(module, q)
        cxt2id = self.CXT2id[module]

        if self.oracle(cxt[0] + q + cxt[1]):
            debug(f"valid {pp(cxt[0])} {pp(q)} {pp(cxt[1])}")
            debug(f"{module} {iq} {cxt2id[cxt]}")
            self.matrices[module][iq, cxt2id[cxt]] = 1
        else:
            self.matrices[module][iq, cxt2id[cxt]] = -1

    def is_new(self, matrix, module, new_q):
        """ Is `new_q` a new representative? """

        if new_q in self.Qs[module]:
            return False

        i_newq = self.add_q2id(module, new_q)

        for q in self.Qs[module]:
            i_q = self.add_q2id(module, q)

            assert new_q != q
            assert i_newq != i_q, self.Q2id[module]

            if (np.array_equal(matrix[i_q], matrix[i_newq])):
                debug(f"not new: {pp(q)} ~ {pp(new_q)}")

                debug("".join(
                    [f"{i_newq} {pp(new_q)} {cxt} " +
                     f"{matrix[i_newq, self.CXT2id[module][cxt]]}"
                     for cxt in self.cxtss[module]]))

                debug("".join(
                    [f"{i_q} {pp(q)} {cxt} " +
                     f"{matrix[i_q, self.CXT2id[module][cxt]]}"
                     for cxt in self.cxtss[module]]))

                for cxt in self.cxtss[module]:
                    icxt = self.CXT2id[module][cxt]

                    if self.oracle(cxt[0] + q + cxt[1]):
                        assert matrix[i_q, icxt] == 1, matrix[i_q, icxt]
                    else:
                        assert matrix[i_q, icxt] == -1, \
                            f"{matrix[i_q, icxt]} module={module}" + \
                            f"cxt={pp_cxt(cxt)} q2={pp(q)}"

                return False

        return True

    def close(self,):
        """ Close the matrix table (`self.matrices`). """

        # NOTE - *Pre-condition*
        #   Forall q in Q, matrix[q] is filled for all contexts.
        #   Forall q in q2id, matrix[q] is filled for all contexts.
        # NOTE - *Post-condition*
        #   (Q, cxts) is closed.

        ITERATION_LIMIT = 0

        work_list: deque[tuple[str, int, TOKEN]] = deque()
        # NOTE - Init work list
        for module in range(self.n_classes):
            for q in self.Qs[module]:
                for m in self.m_terminals:
                    work_list.append((q, module, m))

        while ITERATION_LIMIT < 100000 and work_list:
            ITERATION_LIMIT += 1

            (curr_q, module, m) = work_list.popleft()

            q2id = self.Q2id[module]
            matrix = self.matrices[module]
            Q = self.Qs[module]

            match m:
                case str(c) | (c, _):
                    qc = curr_q + c
                case _:
                    raise ValueError

            if qc not in q2id:
                self.add_q2id(module, qc)
                for cxt in self.cxtss[module]:
                    self.update_matrix(module, cxt, qc)
            else:
                pass

            if self.is_new(matrix, module, qc):
                Q.append(qc)

                for m2 in self.m_terminals:
                    work_list.append((qc, module, m2))

                if module > 0 and qc != "":
                    a, b = self.cals[module - 1], self.rets[module - 1]
                    new_m = (a + qc + b, (a, qc, b))

                    # FIXME - more ret?
                    self.m_terminals.append(new_m)

                    for j in range(self.n_classes):
                        for q in self.Qs[j]:
                            work_list.append((q, j, new_m))

        info(f"{ITERATION_LIMIT} iterations")

        self.print_num_states()
        if work_list:
            raise RuntimeError("Reached iteration limit.")

    def print_mterminals(self,) -> None:
        info(f"m_terminals: " +
             " ".join(pp(mc) for mc in self.m_terminals))

    def print_matrix_info(self,) -> None:
        for module in range(self.n_classes):
            print_matrix(module,
                         self.CXT2id[module], self.matrices[module],
                         self.Qs[module], self.cxtss[module], self.Q2id[module])

    def pp_cxt(self, module) -> str:
        pp_s = [f"M{module} cxts:"]
        for cxt in self.cxtss[module]:
            pp_s.append(f"({pp(cxt[0])},{pp(cxt[1])})")

        return " ".join(pp_s)

    def print_grammar(self,) -> None:
        raise NotImplementedError
        grammar = self.vpa2vpg()

        info("raw grammar")
        # print_grammar(grammar)
        exit(0)

        grammar = reduce_grammar(grammar)

        info("reduced grammar")
        print_grammar(grammar)

        # print_info("merge grammar 2")
        # merge_grammar2(grammar)

        # print_info("merged grammar")
        # mgrammar, acc_nt = merge_grammar(grammar)
        # print_mgrammar(mgrammar, acc_nt)

        return

        dfa = DFA()
        dfa.mapping = matrix2mapping(Q2id, matrix, terminals, Q)
        dfa.states = Q
        dfa.accept_states = [q for q in Q if oracle(q)]

        # s = "<c>"
        # tmp_eq = find_eq(str2id, matrix, Q, s)
        # print("<c> ~", pp(tmp_eq), oracle(s), oracle(tmp_eq))
        # print(matrix[str2id[s], str2id[""]], matrix[str2id[tmp_eq], str2id[""]])
        assert dfa.accept_states, f"Q={Q} s={pp(s)}"

        remove_unacceptable_states(dfa)

        assert run_dfa(pp, dfa, s)

        return dfa

    def add_cxt(self, module: int, cxt: tuple[str, str]):
        """ Add a new context to module. """

        cxt2id = self.CXT2id[module]
        if cxt in cxt2id:
            return
        self.cxtss[module].append(cxt)
        self.add_cxt2id(module, cxt)
        for q in self.Qs[module]:
            self.update_matrix(module, cxt, q)

    def print_Qs(self,) -> None:
        """ Print representatives in all modules. """

        for module in range(self.n_classes):
            info(f"Q (M{module}) is " +
                 ",".join(pp(q) for q in self.Qs[module]))

    def prune_grammar(self, grammar: GRAMMAR) -> GRAMMAR:
        def reachable_alt(reachable_nts, alt: M_TERMINALs):
            for sym in alt:
                match sym:
                    case str():
                        return True
                    case (_, L, _):
                        return L in reachable_nts
            return False
        # NOTE - Found which nonterminals lead to terminal strings
        reachable_nts = [L for L in grammar if "" in grammar[L]]

        MAX_ITERATION = 10000
        num_iteration = 0
        new_reachable = True

        while new_reachable:
            num_iteration += 1
            if num_iteration == MAX_ITERATION:
                # info(pp(list(awaiting_Ls), delim=','))
                raise RuntimeError("Iteration limit reached.")

            new_reachable = False

            for L, alts in grammar.items():
                if L in reachable_nts:
                    continue

                for elem in alts:
                    match elem:
                        case alt, L2:
                            if L2 in reachable_nts:
                                if reachable_alt(reachable_nts, alt):
                                    new_reachable = True
                                    reachable_nts.append(L)
                                    # print('find_reachable', L, '->', L2)
                                    break
                        case '':
                            pass
                        case _:
                            raise ValueError

        print("reachable_nts " + pp(reachable_nts, delim=','))

        # NOTE - remove unreachable rules
        grammar = {L: grammar[L] for L in grammar if L in reachable_nts}
        for L, alts in grammar.items():
            grammar[L] = new_alts = []
            for alt in alts:
                match alt:
                    case c, L2:
                        print('Consider', L, pp_alt(alt))
                        if L2 in reachable_nts:
                            new_alts.append(alt)
                    case _:
                        new_alts.append(alt)

        # TODO - remove below
        print("Pruned grammar")
        print_grammar(grammar)

        return grammar

    def print_num_states(self, ):
        num_states = sum(len(Q) for Q in self.Qs)

        print(num_states, self._oracle.print_info())

        self.consolidate_vpa()

        recall, _ = Eval.compute_recall(
            self.grammar_name, self, self.tokenizer, None)

        grammar = self.vpa2vpg()

        L2str = build_L2str(grammar)

        tokenizer = self.tokenizer

        print("The VPG:")
        for L, alts in grammar.items():
            print(f"    {L} -> {' | '.join(pp_alt(alt) for alt in alts)}")

        sampled_strings = SampleStrings.build_prec_strs(
            tokenizer, self, grammar, L2str)

        assert sampled_strings
        prec, _ = Eval.compute_prec(self.oracle, sampled_strings)

        f1 = 2 * recall * prec / (recall + prec)

        print('R:', recall, 'P:', prec, 'F1:', f1)

        if recall < 0.1:
            exit()

        self.history.append((f1, self._oracle.print_info()))

    def print_history(self,) -> None:
        y_values, x_values = zip(*self.history)
        plt.plot(x_values, y_values)
        plt.xlabel('Number of Membership Queries')
        # plt.ylabel('Number of States')
        plt.title(f'Number of States ({self.grammar_name})')
        plt.grid(True)  # Optional: Add a grid

        plt.show()

        pickle.dump(self.history, open(
            f"result/num_states_{self.grammar_name}", "wb"))

    def consolidate_vpa(self,):
        """ 
        Convert equivalence classes to a more effcient form of VPA. 
        """

        self.acc_states = [q for q in self.Qs[0] if self.oracle(q)]

        for module in range(self.n_classes):
            print(f"Q (M{module}) is " +
                  ",".join(pp(q) for q in self.Qs[module]))
        print("acc states " + pp(self.acc_states, delim=','))

        self.module_q2p_ms = []

        # NOTE - (q,c) -> p, or (q,c,t) -> p
        self.module_transitions = [{} for _ in range(self.n_classes)]

        for module in range(self.n_classes):
            Q = self.Qs[module]
            matrix = self.matrices[module]
            q2id = self.Q2id[module]

            assert Q[0] == ""

            q2p_ms = dict()

            for i, q in enumerate(Q):
                debug(f'M{module} q is ' + pp(q))

                ab_eqqc2ps: defaultdict[tuple[str, str],
                                        defaultdict[str, list[str]]]
                ab_eqqc2ps = defaultdict(lambda: defaultdict(list))
                c_eqqc2ps: defaultdict[str, list[str]] = defaultdict(list)

                for c in self.m_terminals:
                    match c:
                        case str(c):
                            eq_qc = self.find_eq(q2id, matrix, Q, q + c)
                            c_eqqc2ps[eq_qc].append(c)
                        case (ms, (a, p, b)):
                            eq_qc = self.find_eq(q2id, matrix, Q, q + ms)
                            ab_eqqc2ps[a, b][eq_qc].append(p)

                # NOTE - merge the transitions
                for eq_qc, cs in c_eqqc2ps.items():
                    print(f"M{module}: ({pp(q)},{pp(cs)}) -> {pp(eq_qc)}")

                    if (q, eq_qc) not in q2p_ms:
                        q2p_ms[q, eq_qc] = []
                    q2p_ms[q, eq_qc] += cs
                    for c in cs:
                        assert isinstance(c, str)
                        self.module_transitions[module][q, c] = eq_qc

                for (a, b), eq_qc_ps in ab_eqqc2ps.items():
                    cal_module = self.cals.index(a) + 1
                    for eq_qc, ps in eq_qc_ps.items():
                        print(pp(a) + " " + pp(b) + " " + pp(ps, delim=","))

                        for p in ps:
                            if (q, eq_qc) not in q2p_ms:
                                q2p_ms[q, eq_qc] = []

                            q2p_ms[q, eq_qc].append((a, p, b))

                            debug(f"(M{cal_module} {pp(p)}," +
                                  f"{pp(b)},[{module},{pp(q)},{pp(a)}]) -> M{module} {pp(eq_qc)}")

                            if (p, b, (module, q, a)) in self.module_transitions[cal_module]:

                                assert eq_qc == self.module_transitions[
                                    cal_module][p, b, (module, q, a)], f"{pp(self.module_transitions[
                                        cal_module][p, b, (module, q, a)])}"

                            self.module_transitions[
                                cal_module][p, b, (module, q, a)] = eq_qc

                    # NOTE - remove this line for now
                    # self.module_transitions[module][q, a] = ""
            self.module_q2p_ms.append(q2p_ms)

        # exit()

        return self.module_q2p_ms, self.module_transitions

    def run_vpa(self, ce: CE) -> bool:
        """ Run VPA on counterexample `ce`. """

        if not self.module_transitions:
            self.consolidate_vpa()

        stack: list[tuple[int, str, tuple[Token, str]]] = []
        state: str = ""
        module: int = 0

        for i, c in enumerate(ce[1]):
            if isinstance(c, tuple) and c[0].token_type == 'call':
                debug('runvpa', f"(M{module} {pp(state)}," +
                      f"{pp(c[1])}) -> M{c[0].module} {pp('')}")

                stack.append((module, state, c))
                module = c[0].module
                state = ""

            else:
                if isinstance(c, tuple) and c[0].token_type == 'return':
                    if not stack:
                        return False
                    pre_module, q, (call_token, _) = stack.pop()
                    a = call_token.repr
                    b = c[0].repr
                    if (state, b, (pre_module, q, a)) not in self.module_transitions[module]:
                        debug('runvpa', f"(M{module} {pp(state)}," +
                              f"{pp(b)},[{pre_module},{pp(q)},{pp(a)}]) -> ???")
                        return False
                    qc = self.module_transitions[module][state,
                                                         b, (pre_module, q, a)]

                    debug('runvpa', f"(M{module} {pp(state)}," +
                          f"{pp(b)},[{pre_module},{pp(q)},{pp(a)}]) -> {pp(qc)}")

                    module = pre_module
                else:
                    assert isinstance(c, str)
                    debug('runvpa', f"M{module}, {
                          len(self.module_transitions)}")
                    if (state, c) not in self.module_transitions[module]:
                        debug('runvpa', f"(M{module} {
                              pp(state)}, {pp(c)}) -> ???")
                        return False
                    qc = self.module_transitions[module][state, c]
                    debug('runvpa', f"(M{module} {
                          pp(state)}, {pp(c)}) -> {pp(qc)}")

                state = qc

        debug('runvpa', f"stack is {stack}, state is {pp(state)}, " +
              f"acc states are {pp(self.acc_states, delim=',')}")

        return not stack and state in self.acc_states

    def remove_red_states(self,):
        """ Remove states that only transfer to itself. """

        def find_reachable(module):
            new_reachable = False
            q2p_ms = self.module_q2p_ms[module]
            for q, p in list(q2p_ms):
                if q in reachable_states:
                    continue
                if p in reachable_states:
                    new_reachable = True
                    reachable_states.append(q)

                    # for sym in list(q2p_ms[q, p]):
                    #     match sym:
                    #         case str():
                    #             new_reachable = True
                    #             reachable_states.append(q)
                    #             break
                    #         case (_, g, _):
                    #             if g in reachable_states:
                    #                 new_reachable = True
                    #                 reachable_states.append(q)
                    #                 break
            return new_reachable

        def rm_unreachable(module):
            q2p_ms = self.module_q2p_ms[module]
            for q, p in list(q2p_ms):
                if q not in reachable_states or p not in reachable_states:
                    q2p_ms.pop((q, p))
                    continue

                # for sym in list(q2p_ms[q, p]):
                #     match sym:
                #         case (a, g, b):
                #             q2p_ms[q, p].remove((a, g, b))
                #             if not q2p_ms[q, p]:
                #                 q2p_ms.pop((q, p))
                #                 break

        if not self.acc_states:
            self.acc_states = [q for q in self.Qs[0] if self.oracle(q)]
        info("acc states " + pp(self.acc_states, delim=','))

        reachable_states = self.acc_states[:]
        new_reachable = True
        while new_reachable:
            new_reachable = find_reachable(0)

        # for q, p in self.module_q2p_ms[0]:
        #     info(f"{pp(q)} {pp(p)} {pp_cs(self.module_q2p_ms[0][q,p])}")

        rm_unreachable(0)
        info('-----')

        for q, p in self.module_q2p_ms[0]:
            info(f"{pp(q)} {pp(p)} {pp_cs(self.module_q2p_ms[0][q, p])}")
        # exit()

    def remove_redundant_states(self,):
        """ Remove states that only transfer to itself. """

        # if not self.merged_module_transitions:
        #     self.merge_module_transitions()

        for module in range(self.n_classes):

            # trans = self.merged_module_transitions[module]
            q2p_ms = self.module_q2p_ms[module]

            for (q, p), ms in q2p_ms.items():
                assert ms

            rej_state = None
            q2p = defaultdict(list)
            for q, p in q2p_ms:
                q2p[q].append(p)
            for q, ps in q2p.items():
                if len(ps) == 1 and q == ps[0]:
                    rej_state = q
                    info(f"M{module} rej state: " + pp(rej_state))

            if rej_state is None:
                continue

            rejs = set([rej_state])

            while rejs:
                new_rej = set()
                for q, p in list(q2p_ms):
                    if q in rejs:
                        q2p_ms.pop((q, p))
                        continue
                    if p in rejs:
                        q2p_ms.pop((q, p))
                        q2p[q].remove(p)

                        if not q2p[q]:
                            new_rej.add(q)
                        continue

                    for sym in list(q2p_ms[q, p]):
                        match sym:
                            case (a, g, b):
                                if g in rejs:
                                    q2p_ms[q, p].remove((a, g, b))
                                    if not q2p_ms[q, p]:
                                        q2p_ms.pop((q, p))

                rejs = new_rej

            for (q, p), ms in q2p_ms.items():
                assert ms

    def collect_cr2ps(self,):
        """ Return a dict: (a,b) -> {p | (a, p, b) is a terminal} """

        cr2ps: defaultdict[tuple[str, str],
                           set[tuple[str, ...]]] = defaultdict(set)

        for module in range(self.n_classes):
            info(f"{len(self.module_q2p_ms)}, {self.n_classes}")
            for ms in self.module_q2p_ms[module].values():
                sub_cr2ps = defaultdict(set)
                for m in ms:
                    match m:
                        case (a, p, b): sub_cr2ps[a, b].add(p)

                for (a, b), ps in sub_cr2ps.items():
                    cr2ps[a, b].add(tuple(sorted(ps)))

        cr2lps: dict[tuple[str, str],
                     list[tuple[str, ...]]] = {}

        for (a, b), set_ps in cr2ps.items():
            lps = sorted(set_ps)
            cr2lps[a, b] = lps
            for ps in lps:
                info(f"({pp(a)},{pp(b)}): " + pp(list(ps), delim=","))

        return cr2lps

    def build_sub_grammar(self,
                          ab_ps2i: dict[tuple[str, str, tuple[str, ...]], int]):
        """ ONGOING """

        if not self.acc_states:
            self.acc_states = accept_q = [
                q for q in self.Qs[0] if self.oracle(q)]
            debug("acc states " + pp(accept_q, delim=','))

        def i2prefix(i: int):
            return f"m{i}_"

        def q2nt(module, q):
            # if q == 'L = L':
            #     print('L = L is mapped to', f"L{module_q2nti[module][q]}")
            return f"L{module_q2nti[module][q]}"

        self.print_Qs()
        module_q2nti = [{} for _ in range(self.n_classes)]

        module_rules = [defaultdict(list) for _ in range(self.n_classes)]

        for module in range(self.n_classes):
            rules: defaultdict[
                str,
                ALTs]
            rules = module_rules[module]
            q2nti = module_q2nti[module]
            for q in self.Qs[module]:
                q2nti[q] = len(q2nti)

            for (q, p), ms in self.module_q2p_ms[module].items():
                ps = defaultdict(set)
                cs: M_TERMINALs = []
                for m in ms:
                    match m:
                        case (a, p2, b): ps[a, b].add(p2)
                        case str(c): cs.append(c)

                for (a, b), ps in ps.items():
                    cs.append(
                        (a, i2prefix(ab_ps2i[a, b, tuple(sorted(ps))]) + 'L0', b))

                rules[q2nt(module, q)].append((cs, q2nt(module, p)))

        grammar: IGRAMMAR = {}
        # NOTE - for module 0
        for q in self.acc_states:
            # print('adding "" to acc ', q2nt(0, q))
            module_rules[0][q2nt(0, q)].append("")

        grammar[0] = module_rules[0]

        for (a, b, ps), i in ab_ps2i.items():

            module_call = self.cals.index(a) + 1
            rules = module_rules[module_call]
            grammar[i] = {k: v[:] for k, v in rules.items()}
            assert len(ps) == len(set(ps))
            for p in ps:
                assert () not in grammar[i][q2nt(module_call, p)], f"{
                    i} p={pp(p)} {ps}"
                grammar[i][q2nt(module_call, p)].append("")

        return grammar

    def vpa2vpg(self,) -> GRAMMAR:
        """ Convert VPA to a VPG. """

        if not self.module_q2p_ms:
            self.consolidate_vpa()

        cr2lps = self.collect_cr2ps()

        ab_ps2i: dict[tuple[str, str, tuple[str, ...]], int] = {}

        for (a, b), lps in cr2lps.items():
            for ps in lps:
                ab_ps2i[a, b, ps] = len(ab_ps2i) + 1

        igrammar = self.build_sub_grammar(ab_ps2i)

        grammar: GRAMMAR = {}

        for i, rules in enumerate(igrammar.values()):
            for L, alts in rules.items():
                mL = f"m{i}_" + L
                print('vpa2vpg:', mL, ':', ' | '.join(pp_alt(alt)
                      for alt in alts))
                assert mL not in grammar
                grammar[mL] = []
                for alt in alts:
                    match alt:
                        case "":
                            grammar[mL].append("")
                        case (ms, L2):
                            grammar[mL].append((ms, f"m{i}_" + L2))

        return self.prune_grammar(grammar)


def build_L2str(grammar: GRAMMAR) -> dict[str, set[str]]:
    """ 
    Return a dict L2str that maps nonterminal L to some of its strings. 
    Also remove redundancy in `grammar`.
    """

    def collect_alt(ms: M_TERMINALs):
        strs: list[str] = []

        for sym in ms:
            match sym:
                case (a, L, b):
                    strs.extend([a + sL + b for sL in L2str[L]])
                case str(c):
                    strs.append(c)

        return strs

    MAX_ITERATION = 10000

    L2str: dict[str, set[str]] = {L: set() for L in grammar}
    awaiting_Ls: set[str] = set(grammar.keys())

    len_awaiting_Ls = len(awaiting_Ls)
    num_iteration = 0
    while awaiting_Ls:
        num_iteration += 1
        if num_iteration == MAX_ITERATION:
            raise RuntimeError("Iteration limit reached.")

        # print([(_n, _ls) for (_n, _ls) in L2str.items() if _ls])

        for L, alts in grammar.items():
            if L not in awaiting_Ls:
                continue

            for elem in alts:
                match elem:
                    case alt, L2:
                        if L2 not in awaiting_Ls:
                            assert L2str[L2], L2
                            alt_strs = collect_alt(alt)
                            if alt_strs:
                                for s1 in alt_strs:
                                    for s2 in L2str[L2]:
                                        L2str[L].add(s1 + s2)

                                # print(L, 'alt_strs', alt_strs)

                                awaiting_Ls.remove(L)
                                break
                    case '':
                        L2str[L].add('')
                        awaiting_Ls.remove(L)
                    case _:
                        raise ValueError

        if len_awaiting_Ls == len(awaiting_Ls):
            # print('awaiting_Ls:', pp(list(awaiting_Ls), delim=','))
            raise RuntimeError
        len_awaiting_Ls = len(awaiting_Ls)

    return L2str


def remove_redundant_rules(grammar: GRAMMAR) -> None:
    """ Remove redundant rules that never derives a string. """

    rej_nts = []

    for L, alts in grammar.items():
        match alts:
            case [(*_, L1)] if L1 == L:
                rej_nts.append(L)

    def invalid_alt(cs):
        for sym in cs:
            match sym:
                case (_, L2, _) if L2 in rej_nts:
                    return True
        return False

    need_updated = True
    while need_updated:
        need_updated = False

        for L, alts in list(grammar.items()):
            if L in rej_nts:
                grammar.pop(L)
                continue

            new_alts = []
            for alt in alts:
                match alt:
                    case "":
                        new_alts.append(alt)
                    case (cs, L1):
                        if L1 in rej_nts:
                            continue

                        if invalid_alt(cs):
                            continue

                new_alts.append(alt)

            if not new_alts:
                grammar.pop(L)
                rej_nts.append(L)
                need_updated = True

            grammar[L] = new_alts

    info("Reduced:")

    for L, alts in grammar.items():
        info(f"{L} -> {' | '.join(pp_alt(alt) for alt in alts)}")


def load_learner(name, folder='learner') -> VPALearner:
    """ Load the stored leaner. """

    file_folder = os.path.join(path_to_result, folder)
    file_path = os.path.join(file_folder, f"{name}.pickle")
    with open(f"{file_path}", "rb") as f:
        learner = pickle.load(f)

    return learner


def build_counterexamples(
        oracle: Oracle, tokenizer: Tokenizer,
        cr2cxt: dict[tuple[str, str], list[tuple[str, str, str]]],
        extra_strs: list[str],
        plain_valid_strs: list[str]) -> list[CE]:
    """
    Simulate equivalence queries using potential counterexamples.
    Enhance data by combining prefixes, suffixes and infixes of the 
    seed strings.Specifically, strings in Module 0 are special: they are not 
    nested by call and return tokens. Therefore, we need to use them to 
    enhance the valid strings explicitly.
    """

    def subij(z, min_len_z):
        for i in range(len(z) - min_len_z + 1):
            for j in range(i + min_len_z, len(z) + 1):
                yield i, j

    # NOTE - use plain strings to enhance the dataset
    for (a, b), cxts in cr2cxt.items():
        for s in plain_valid_strs:
            for u, z, v in cxts:
                if len(z) == 1 and oracle(u + a + b + v):
                    min_len_z = 2
                else:
                    min_len_z = 1

                for i, j in subij(z, min_len_z):
                    test_s = u + a + z[:i] + s + z[j:] + b + v
                    if test_s not in extra_strs and oracle(test_s):
                        # info("plain enhance " + pp(test_s))
                        extra_strs.append(test_s)

                        test_s2 = a + z[:i] + s + z[j:] + b
                        if test_s2 not in extra_strs:
                            # info("plain enhance 2 " + pp(test_s2))
                            extra_strs.append(test_s2)

    # NOTE - enhance inner strings of matched strings
    for (a, b), cxts in cr2cxt.items():
        for u, z, v in cxts:
            for i, j in subij(z, 2):
                test_s = u + a + z[:i] + z[i:j] * 3 + z[j:] + b + v
                if test_s not in extra_strs and oracle(test_s):
                    extra_strs.append(test_s)
                    # info("nest enhance " + pp(test_s))
                    break

    # NOTE - use strings with plain prefixes to enhance the dataset
    min_len_z = 1
    for (a, b), cxts in cr2cxt.items():

        for u, z, v in cxts:
            debug(f"{a}, {b}, {u}, {z}, {v}")

            if not u:
                continue

            s = u + a + z + b + v
            for i in range(len(z) - min_len_z + 1):
                for j in range(i + min_len_z, len(z) + 1):
                    test_s = u + a + z[:i] + s + z[j:] + b + v
                    debug("test_s " + test_s)
                    if test_s not in extra_strs and oracle(test_s):
                        # info("prefix nest enhance " + pp(test_s))
                        extra_strs.append(test_s)

    # NOTE - Remove plain prefixes to enhance the dataset
    for (a, b), cxts in cr2cxt.items():
        for u, z, v in cxts:
            if u == "" and v == "":
                test_s = a + z + b
                if test_s not in extra_strs and oracle(a):
                    extra_strs.append(test_s)

    # NOTE - Merge infixes to enhance the dataset
    for (a, b), cxts in cr2cxt.items():
        for (u1, z1, v1), (u2, z2, v2) in combinations(cxts, 2):
            test_s = u1 + a + z1 + z2 + b + v1
            if test_s not in extra_strs:
                extra_strs.append(test_s)

    # NOTE - now, convert strings to counter-examples
    ces: list[CE] = []
    for s in sorted(extra_strs):
        tokens = tokenizer.eagar_tokenize(s)
        ce = expand_tokens(s, tokens)
        ces.append(ce)

    return ces


def learn_vpa(oracle: Oracle, tokenizer: Tokenizer, terminals: list[str],
              cr2cxt: dict[tuple[str, str], list[tuple[str, str, str]]],
              seed_strings: list[str],
              pln_strings: list[str],
              extra_valid_strs: list[str],
              plain_valid_strs: list[str]) -> tuple[VPALearner, int]:
    """ Learn a VPA from oracle, tokenizer, and terminals.

    Return: VPA Learner and the number of counterexamples used. """

    # NOTE - init contexts
    cxtss: list[list[list[tuple[str, str]]]] = [[[("", "")]]]

    # NOTE - collect contexts for Module i>0
    for (a, b), cxts in cr2cxt.items():
        cxtss.append([[(a, b)]] +
                     [[(u + a, z[:i] + b + v) for i in range(len(z))]
                      for u, z, v in cxts])

    # NOTE - collect contexts for Module 0
    for ce in pln_strings:
        cxtss[0].append([("", ce[i:]) for i in range(len(ce))])

    init_cxts = [remove_duplicates_keep_order(
        sum(cxt[:2], [])) for cxt in cxtss]

    cals: list[str] = [a for a, _ in cr2cxt]
    rets: list[str] = [b for _, b in cr2cxt]

    info("terminals: " + pp(terminals, delim=','))

    # NOTE - Time to learn!
    learner = VPALearner(oracle, cals, rets, sorted(
        terminals), init_cxts, tokenizer)

    info(learner.pp_cxt(1))

    learner.close()

    counter_examples = build_counterexamples(
        oracle, tokenizer, cr2cxt,
        extra_valid_strs + seed_strings, pln_strings + plain_valid_strs)

    for (ce, _) in counter_examples:
        info("countlerexample " + pp(ce))

    need_update = True

    MAX_ITERATION = 30000

    while need_update:
        need_update = False
        breaked_ce = None
        num_iteration = 0
        for i_ce, ce in enumerate(counter_examples):
            info('ce: ' + pp_ce(ce))
            new_breaked_ce = learner.break_counterexample(ce)

            # for _i, _ce in enumerate(counter_examples[:i_ce]):
            #     assert learner.break_counterexample(_ce) is None, f"{_i}, {i_ce}, {pp_ce(_ce)}, {pp_ce(ce)}"

            if not new_breaked_ce:
                continue

            need_update = True

            if breaked_ce:

                if breaked_ce == new_breaked_ce:
                    print(f"new_q is {pp(new_q)}")
                    print(f"terminals: " +
                          " ".join(pp(c) for c in learner.m_terminals))
                    learner.print_Qs()
                    learner._oracle.print_info()
                    learner.print_matrix_info()
                    raise RuntimeError("No Progress")

            breaked_ce = new_breaked_ce

            num_iteration += 1
            if num_iteration == MAX_ITERATION:
                raise RuntimeError("Iteration limit reached.")

            (module, new_cxt, new_q) = breaked_ce
            info(f"CE ({i_ce}/{len(counter_examples)}): " +
                 f"break {pp(ce[0])} as (M{module}, new_cxt " +
                 f"({pp(new_cxt[0])},{pp(new_cxt[1])},{pp(new_cxt[2])}), new_q {pp(new_q)})")

            learner.add_q2id(module, new_q)
            learner.Qs[module].append(new_q)

            if module > 0:
                a, b = cals[module - 1], rets[module - 1]
                new_m = (a + new_q + b, (a, new_q, b))
                learner.m_terminals.append((new_m))

            for cxt in learner.cxtss[module]:
                learner.update_matrix(module, cxt, new_q)

            new_cxts = [(new_cxt[0], (new_q + new_cxt[1])[j:])
                        for j in range(len(new_q + new_cxt[2]) + 1)]

            for nc in new_cxts:
                debug(nc)

                learner.add_cxt(module, nc)

                for q in learner.Q2id[module]:
                    learner.update_matrix(module, nc, q)

            learner.close()

    learner.print_history()

    return learner, len(counter_examples)
