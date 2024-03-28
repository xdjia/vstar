from collections import defaultdict, deque
import datetime
import os
import pickle
import re
from typing import Callable, Optional

from vstar.EnumStr import subStr
from vstar.Automata import single_str_udfa
from vstar.NestingPattern import IntervalDict, indices2pattern, pp_pattern, refine_patterns
from .EnumStr import allsubs_maxmin

from vstar.Token import CE, Token, pp_ce, pp_tokens
from vstar.Utils import err, info, path_to_result, warning
from .RE import expand_alternation, list_alts, pp_re, re2pyre, Star
from .Automata import UDFA, mfa_less, mfa_equiv, print_dfa, pp_udfa

from .Automata import dfa2udfa

from .MatrixLStar import learn_dfa
from .Utils import pp, debug
from .DFA2RE import udfa2re

from .Oracle import Oracle


class Tokenizer:
    """
    Tokenizer: str -> list[Token]
    """

    def __init__(self) -> None:
        self.tokens: list[Token] = []
        self.chars: list[str] = []
        self.call2ret: dict[Token, Token] = {}
        self.ret2call: dict[Token, Token] = {}

    def addCR(self, new_ctoken: Token, new_rtoken: Token):
        def contain2(call1: Token, call2: Token, ret1: Token, ret2: Token):
            return (mfa_less(call1.udfa, call2.udfa) and
                    mfa_less(ret1.udfa, ret2.udfa))

        def already_exist():

            debug(f"New ctoken's UDFA:")
            debug(pp_udfa(new_ctoken.udfa))

            for ctoken, rtoken in self.call2ret.items():

                debug("Compare " +
                      pp_re(ctoken.rex, []) +
                      pp_re(rtoken.rex, []) +
                      pp_re(new_ctoken.rex, []) +
                      pp_re(new_rtoken.rex, []))

                if contain2(ctoken, new_ctoken, rtoken, new_rtoken):
                    # FIXME - Simple check
                    return True

                if contain2(new_ctoken, ctoken, new_rtoken, rtoken):
                    self.tokens.remove(ctoken)
                    self.tokens.remove(rtoken)
                    self.tokens.append(new_ctoken)
                    self.tokens.append(new_rtoken)

                    self.call2ret.pop(ctoken)
                    self.call2ret[new_ctoken] = new_rtoken

                    return True

                cont1 = mfa_less(new_ctoken.udfa, ctoken.udfa)
                cont2 = mfa_less(new_rtoken.udfa, rtoken.udfa)
                cont3 = mfa_less(ctoken.udfa, new_ctoken.udfa)
                cont4 = mfa_less(rtoken.udfa, new_rtoken.udfa)

                if (cont1 or cont2 or cont3 or cont4):
                    print(cont1, cont2, cont3, cont4)
                    raise ValueError(f"")

            return False

        if already_exist():
            return

        info(f"New call token added: {pp_re(new_ctoken.rex, [])}")
        info(f"New retn token added: {pp_re(new_rtoken.rex, [])}")

        self.call2ret[new_ctoken] = new_rtoken
        self.ret2call[new_rtoken] = new_ctoken

        self.tokens.append(new_ctoken)
        self.tokens.append(new_rtoken)

    def addPln(self, new_pln: Token):
        def print_res():
            info(f"New\t{pp_re(new_pln.rex, self.chars)}")
            info(f"Existing\t{pp_re(token.rex, self.chars)}")

        for token in self.tokens:

            if mfa_equiv(new_pln.udfa, token.udfa):
                print_res()
                err("New == Exist; New not added")
                return

            elif mfa_less(new_pln.udfa, token.udfa):
                print_res()
                err("New < Exist; New not added")
                return

            elif mfa_less(token.udfa, new_pln.udfa):
                print_res()
                err("Exist < New; Replace existing with new")
                self.tokens.remove(token)
                self.tokens.append(new_pln)
                return

        info(f"New pln added: {pp_re(new_pln.rex, [])}")
        self.tokens.append(new_pln)

    def remove(self, call_token: Token, ret_token: Token):
        self.tokens.remove(call_token)
        self.tokens.remove(ret_token)
        self.call2ret.pop(call_token)

    def __str__(self, ):

        s = f"{len(self.tokens)} tokens: " + ' '.join(pp_re(token.rex, [])
                                                      for token in self.tokens)
        return s

    def tokenize(self, s) -> list[tuple[Token, str]]:

        tokens = []

        index = 0

        while index < len(s):
            m = None  # NOTE - Re Match
            debug(f"Search {pp(s[index:])}")

            max_index = -1
            t = None
            for token in self.tokens:
                m = token.match(s, index)
                if m:
                    if m.end() > max_index:
                        max_index = m.end()
                        t = token
                        # break
                    elif False and m.end() == max_index:

                        print(
                            f"New plain re {pp_re(t.rex, all_chars=self.chars)}")
                        print(
                            f"Old plain re {pp_re(token.rex, all_chars=self.chars)}")
                        info(f"t     -> {t.match(s).group()}")
                        info(f"token -> {token.match(s).group()}")
                        info(
                            f"t     {pp_re(t.rex, all_chars=self.chars)}")
                        print(
                            f"token {pp_re(token.rex, all_chars=self.chars)}")
                        if mfa_less(t.udfa, token.udfa):
                            mfa_less(token.udfa, t.udfa, debug=True)
                            info(f"t < token")
                        else:
                            mfa_less(t.udfa, token.udfa, debug=True)
                            info(f"t > token")

                        raise ValueError(
                            f"Ambiguious tokenization s={pp(s)} t1={pp(t.s)} t2={pp(token.s)} {len(tokens)}")

            if t is None:
                info(self)
                raise ValueError(
                    f"Cannot tokenize string {pp(s)} at {pp(s[index:])}")
            else:
                tokens.append((t, s[index:max_index]))

                info(
                    f"separate {pp(s[index:max_index])} from {pp(s[index:])} of token {pp(t.strs)} {pp_re(t.rex, self.chars)}")
                index = max_index

        return tokens

    def eagar_tokenize(self, s: str) -> list[tuple[Token, re.Match]]:
        """
        Eagerly tokenize a string: tokenize as long as a substring can 
        be matched.
        """

        tokens = []

        index = 0

        while index < len(s):
            ms = []  # NOTE - Re Match

            debug(f"Search {pp(s[index:])}")

            for token in self.tokens:
                m = token.search(s, index)
                if m:
                    ms.append(m)

            if not ms:
                debug(self)
                debug(f"Cannot tokenize {pp(s)} at {pp(s[index:])}")
                break
            else:
                (token, m) = min(ms, key=lambda x: x[1].start())
                index = m.end()
                tokens.append((token, m))

        return tokens


def print_expanded_re(chars, r):
    """ Expand a regular expression and print it. """

    for rr in expand_alternation(r):

        if isinstance(rr, list) and len(rr) > 1 and ('z' not in rr and '1' not in rr and '-' not in rr):
            print_expanded_re(chars, rr)
        else:
            info(f"    alt:" + pp_re(rr, chars), )


def test_print_expanded_re(chars, r):
    info(f"r={r}")
    print_expanded_re(chars, r)
    exit()


def learn_token(local_oracle: Callable[[str], bool],
                chars: list[str],
                strs: list[str],
                pref: str,
                suff: str) -> Token:
    """ Learn a token from local oracle and strs. """

    suffixes = list(
        set(list(s[i:j] for s in strs[:2]
                 for i, j in allsubs_maxmin(s, 1)) + [""]))

    suffixes.sort()

    info(f"suffixes: {len(suffixes)}, {pp(suffixes, delim=',')}")

    dfa = learn_dfa(local_oracle, chars, suffixes)
    udfa = dfa2udfa(dfa)
    # debug(pp_udfa(udfa))
    udfa.add_prefix(pref)
    # debug(pp_udfa(udfa))
    udfa.add_suffix(suff)
    # debug(pp_udfa(udfa))

    rex = udfa2re(udfa)

    info(f"Found RE:, {pp_re(rex, chars)}")

    token = Token(rex=rex, strs=strs, udfa=udfa)

    return token


# NOTE - folder to store the tokenizer
tokenizer_folder = os.path.join(path_to_result, "learned_tokenizer")


def dump_tokenizer(tokenizer: Tokenizer, name="tmp", no_time=False):
    """ Store the tokenizer to disk. """

    data = tokenizer

    if no_time:
        file_name = name
    else:
        current_datetime = datetime.datetime.now()
        formatted_datetime = current_datetime.strftime("%Y-%m-%d_%H-%M-%S")
        file_name = f"{name}_{formatted_datetime}"

    if not os.path.exists(tokenizer_folder):
        os.mkdir(tokenizer_folder)

    file_path = os.path.join(tokenizer_folder, f"{file_name}.pickle")
    with open(file_path, "wb") as f:
        pickle.dump(data, f)

    info(f"tokenizer saved as {file_path}")


def load_tokenizer(name) -> Tokenizer:
    """ Load tokenizer from disk. """

    file_path = os.path.join(tokenizer_folder, f"{name}.pickle")

    if not os.path.exists(file_path):
        raise ValueError('No tokenizer.')

    with open(f"{file_path}", "rb") as f:
        tokenizer = pickle.load(f)

    info("Loaded " + file_path)

    return tokenizer


def explore_internal_cr(oracle, test_strings: list[str],
                        make_test_s: Callable[[str], str],
                        a: str, valid_strs: list[str],
                        plain_valid_strs: list[str]) -> list[int]:
    """ Refine candidate call/return strings. """

    valid_i = []
    subss: list[str] = []

    min_len_a = 2
    for i in range(1, len(a) - min_len_a + 1):
        for j in range(i + min_len_a, len(a) + 1):
            a1, a2, a3 = a[:i], a[i:j], a[j:]
            # info(pp(a1), pp(a2), pp(a3))
            for s in test_strings:
                for subs in subStr(s, 2):
                    if subs == a2 or a.endswith(subs):
                        continue
                    test_s = make_test_s(a1 + subs + a3)

                    if test_s not in valid_strs and oracle(test_s):
                        if not valid_i or valid_i[-1] != i:
                            valid_i.append(i)
                        if subs not in subss:
                            subss.append(subs)
                        if a2 not in subss:
                            subss.append(a2)
                        if test_s not in valid_strs:
                            valid_strs.append(test_s)

                        debug(f"({pp(a1)}, {pp(a2)}, {pp(a3)})" +
                              f"s={pp(s)}>{pp(subs)}: {pp(test_s)}")

            continue

    debug("subss: " + pp(subss, delim=','))

    for s in test_strings:
        for subs in subss:
            for k in range(1, len(s)):
                for l in range(i + 1, len(s) + 1):
                    test_s = s[:k] + subs + s[l:]
                    if oracle(test_s):
                        if test_s not in valid_strs:
                            valid_strs.append(test_s)
                            plain_valid_strs.append(test_s)

    return valid_i


def validate_tokenizer(tokenizer: Tokenizer,
                       strings: list[str], refine=False) -> bool:
    """ Make tokenizer gives well-matched tokens for strings. """

    for s in strings:
        tokens = tokenizer.eagar_tokenize(s)
        debug(pp_tokens(s, tokens))

        st = []
        for token in tokens:
            if token[0].token_type == 'call':
                st.append(token)
            else:
                if not st:
                    if not refine:
                        return False

                    # NOTE - refine call token
                    call_token = tokenizer.ret2call[token[0]]

                    info(f"{call_token}: {pp(call_token.strs, delim='|')}")

                    repr_s = token[0].strs[0]

                    for c in repr_s:
                        call_backup = call_token.copy()
                        call_token.set(Token(
                            rex=c, strs=[c], udfa=single_str_udfa(c),
                            token_type="call"))
                        # NOTE - replace call token with candidate call token
                        if validate_tokenizer(tokenizer, strings, False):
                            info(f"Use {pp(c)} to replace the call token")
                            return validate_tokenizer(tokenizer, strings, True)

                    call_token.set(call_backup)
                    raise ValueError("Assumption broken.")

                call_token = st.pop()
                if token[0] is not tokenizer.call2ret[call_token[0]]:
                    assert refine
                    return False

        if st:
            assert refine
            return False

    return True


def validate(
    cr2cxt: dict[tuple[str, str], list[tuple[str, str, str]]],
    x: str, y: str
) -> Optional[tuple[str, str]]:
    """ If nesting pattern (x,y) is contained in existing patterns. """

    for (x2, y2) in cr2cxt:
        if x2 == x or y2 == y:
            return (x2, y2)

    return None


def collect_cr2cxt(oracle, intervalDict: IntervalDict):
    """
    Collect nesting patterns that share the same call/return strings.

    Return:
        cr2crs: call/return strings that belong to the same pair.
        cr2cxt: (u,z,v) for each pair.
    """

    # NOTE - (x, y) ↦ [(u,z,v),...]
    cr2cxt: dict[tuple[str, str], list[tuple[str, str, str]]]
    cr2crs: dict[tuple[str, str], list[tuple[str, str]]]
    cr2cxt = defaultdict(list)
    cr2crs = defaultdict(list)

    for s in intervalDict:
        intervals = list(zip(*intervalDict[s]))
        # NOTE - proritize shorter patterns
        intervals.sort(key=lambda x: (x[0][1] - x[0][0], x[1][1] - x[1][0]))

        for (i1, j1), (i2, j2) in intervals:
            (_, u, x, z, y, v) = indices2pattern(s, i1, j1, i2, j2)

            match validate(cr2cxt, x, y):
                case (x2, y2):
                    for (u2, z2, v2) in cr2cxt[x2, y2]:
                        if not oracle(u2 + x + z2 + y + v2):
                            debug("Incompatible")
                            debug(pp_pattern((s, u2, x2, z2, y2, v2)))
                            debug(pp_pattern((s, u, x, z, y, v)))

                            if x == x2:
                                # NOTE - refine y and y2
                                if y2 in y:
                                    # NOTE - refine x2 as x
                                    i2 = len(u) + len(x) + len(z) + y.index(y2)
                                    j2 = i2 + len(y2)
                                else:
                                    # NOTE - enumerate substrings
                                    raise NotImplementedError
                            else:
                                # NOTE - refine x and x2
                                if x2 in x:
                                    # NOTE - refine x2 as x
                                    i1 = len(u) + x.index(x2)
                                    j1 = i1 + len(x2)
                                else:
                                    # NOTE - enumerate substrings
                                    raise NotImplementedError

                            (_, u, x, z, y, v) = indices2pattern(
                                s, i1, j1, i2, j2)
                            debug('new pattern:' +
                                  pp_pattern((s, u, x, z, y, v)))

                            break

                    cr2cxt[x2, y2].append((u, z, v))
                    cr2crs[x2, y2].append((x, y))
                case None:
                    cr2cxt[x, y].append((u, z, v))
                    cr2crs[x, y].append((x, y))

    info_cr2cxt(cr2cxt)

    return cr2crs, cr2cxt


def learn_tokenizer(oracle: Oracle,
                    intervalDict: IntervalDict,
                    pln_strings: list[str],
                    chars: list[str]):
    """ Learn a tokenizer from nesting patterns. """

    refine_patterns(intervalDict)

    cr2crs, cr2cxt = collect_cr2cxt(oracle, intervalDict)

    plain_valid_strs = []
    valid_strs = []

    for (a, b), crs in list(cr2crs.items()):
        calls = set(a2 for a2, _ in crs)
        retns = set(b2 for _, b2 in crs)
        cxts = list(set(cr2cxt[a, b]))
        u, z, v = cxts[0]

        for s in pln_strings:
            test_s = u + a + s + b + v
            if oracle(test_s):
                if test_s not in valid_strs:
                    valid_strs.append(test_s)

        valid_ai, valid_bi = [], []

        if len(a) > 1:
            valid_ai = explore_internal_cr(
                oracle, pln_strings, lambda s: u + s + z + b + v, a,
                valid_strs, plain_valid_strs)

        if len(b) > 1:
            valid_bi = explore_internal_cr(
                oracle, pln_strings, lambda s: u + a + z + s + v, b,
                valid_strs, plain_valid_strs)

        match valid_ai, valid_bi:
            case [], []: pass

            case [min_i, *_], []:
                min_i = valid_ai[0]
                a1, a2 = a[:min_i], a[min_i:]
                assert (a1, b) not in cr2crs
                cr2crs[a1, b] = [(c[:min_i], r) for c, r in cr2crs[a, b]]
                cr2cxt[a1, b] = [(u, a2 + z, v) for u, z, v in cr2cxt[a, b]]

            case [*_, min_j], []:
                min_j = valid_bi[0]
                b1, b2 = b[:min_j], b[min_j:]

                assert (a, b1) not in cr2crs
                cr2crs[a, b1] = [(c, r[:min_j]) for c, r in cr2crs[a, b]]
                cr2cxt[a, b1] = [(u, z, b2 + v) for u, z, v in cr2cxt[a, b]]

            case [min_i, *_], [*_, min_j]:
                min_i = valid_ai[0]
                a1, a2 = a[:min_i], a[min_i:]

                min_j = valid_bi[0]
                b1, b2 = b[:min_j], b[min_j:]

                assert (a1, b1) not in cr2crs, (a1, b1)
                cr2crs[a1, b1] = [(c[:min_i], r[:min_j])
                                  for c, r in cr2crs[a, b]]
                cr2cxt[a1, b1] = [(u, a2 + z, b2 + v)
                                  for u, z, v in cr2cxt[a, b]]

        if valid_ai or valid_bi:
            del cr2crs[a, b]
            del cr2cxt[a, b]

    for s in plain_valid_strs:
        debug('plain_valid_strs ' + pp(s))

    # NOTE - learn tokenizer

    tokenizer = Tokenizer()
    tokenizer.chars = chars

    a2token: dict[str, Token] = {}

    for module, ((a, b), crs) in enumerate(cr2crs.items()):
        calls = set(a2 for a2, _ in crs)
        retns = set(b2 for _, b2 in crs)
        cxts = list(set(cr2cxt[a, b]))

        # NOTE - learn call token
        if len(a) == 1:
            assert len(calls) == 1
            call_token = Token(rex=a, strs=list(
                calls), udfa=single_str_udfa(a))

        else:
            def cal_oracle(s: str):
                return all(oracle(u + a[0] + s + a[-1] + z + b + v)
                           for u, z, v in cxts)
            info(
                f"Learn call token from xs {pp(list(calls), delim=',')} " +
                f"uzvs {pp(cxts, delim=',')}",)
            inner_cxts = [w[1:-1] for w in calls]
            call_token = learn_token(
                cal_oracle, chars, inner_cxts, a[0], a[-1])
            call_token.strs = list(calls)

        # NOTE - learn retn token
        if len(b) == 1:
            assert len(retns) == 1
            retn_token = Token(rex=b, strs=list(
                calls), udfa=single_str_udfa(b))
        else:
            def ret_oracle(s: str):
                return all(oracle(u + a + z + b[0] + s + b[-1] + v)
                           for u, z, v in cxts)
            info(f"Learn ret token from string" + pp(list(retns)))
            inner_cxts = [w[1:-1] for w in retns]
            retn_token = learn_token(
                ret_oracle, chars, inner_cxts, b[0], b[-1])
            retn_token.strs = list(retns)

        call_token.token_type = 'call'
        retn_token.token_type = 'return'
        tokenizer.addCR(call_token, retn_token)
        call_token.module = module + 1
        call_token.repr = a
        retn_token.repr = b

        a2token[a] = call_token

    validate_tokenizer(tokenizer,
                       list(intervalDict.keys()) + pln_strings,
                       refine=True)

    debug(tokenizer)

    assert validate_tokenizer(tokenizer, list(valid_strs))

    for s in valid_strs:
        tokens = tokenizer.eagar_tokenize(s)
        debug(pp_tokens(s, tokens))

    # NOTE - merge call-return pairs
    crs = deque((a, b) for a, b in cr2cxt.keys()
                if len(a) > 1 or len(b) > 1)

    while crs:
        a, b = crs.popleft()

        call_token = a2token[a]
        retn_token = tokenizer.call2ret[call_token]

        cxts = cr2cxt[a, b]
        for a2, b2 in list(crs):
            if all(oracle(u + a2 + z + b2 + v) for u, z, v in cxts):

                call_token2 = a2token[a2]
                retn_token2 = tokenizer.call2ret[call_token2]

                # NOTE - merge (a2,b2) to (a,b)
                merge_token(call_token, call_token2)
                merge_token(retn_token, retn_token2)

                crs.remove((a2, b2))
                tokenizer.tokens.remove(call_token2)
                tokenizer.tokens.remove(retn_token2)
                tokenizer.call2ret.pop(call_token2)

                cr2crs[a, b] += cr2crs[a2, b2]
                cr2cxt[a, b] += cr2cxt[a2, b2]

                cr2crs.pop((a2, b2))
                cr2cxt.pop((a2, b2))

    # NOTE - update module index
    for i, (a, b) in enumerate(cr2cxt):
        a2token[a].module = i + 1

    info_cr2cxt(cr2cxt)

    dump_tokenizer(tokenizer, oracle.name, no_time=True)

    return tokenizer, cr2crs, cr2cxt, valid_strs, plain_valid_strs


def merge_token(t1: Token, t2: Token):
    """ token r + token r' ==> token (r|r') """

    match t1.rex:
        case list(rex1):
            rex1.append(t2.rex)
        case _:
            t1.rex = [t1.rex, t2.rex]
    t1.re = re.compile(re2pyre(t1.rex))
    t1.strs += t2.strs
    # t1.udfa = None  # TODO - update the udfa


def info_cr2cxt(cr2cxt):
    """ Print info of call-return pairs' contexts. """
    for i, ((x, y), uzvs) in enumerate(cr2cxt.items()):
        info(f"{i}. ({pp(x)},{pp(y)}): " +
             ' | '.join(pp([u, z, v]) for u, z, v in uzvs))


def expand_tokens(s, tokens) -> CE:
    """ Convert eager tokens to a counter example. """

    ce = []
    i = 0
    for (token, m) in tokens:
        for j in range(i, m.start()):
            ce.append(s[j])

        ce.append((token, s[m.start(): m.end()]))
        i = m.end()

    for j in range(i, len(s)):
        ce.append(s[j])

    return (s, ce)


def tokenize_string(grammar_name: str, s: str):
    """ Tokenize eagerly string s. """

    tokenizer = load_tokenizer(grammar_name)
    tokens = tokenizer.eagar_tokenize(s)
    ce = expand_tokens(s, tokens)
    info("Token list:" + pp_ce(ce))
    
    return ce
