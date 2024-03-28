from collections import deque, Counter, defaultdict
from .Utils import pp
from .Colors import yellow, red
from .Utils import lowercase, digits, digits_but0, err, info, debug


class DFA:
    def __init__(self, ):
        """ A deterministic finite state automaton. """

        # NOTE - transition (q, c) -> p
        self.mapping: dict[tuple[str, str], str] = {}

        self.states: list[str] = []
        self.accept_states: list[str] = []

    def __iter__(self,):
        return self.mapping.__iter__()

    def __getitem__(self, index):
        return self.mapping[index]

    def __setitem__(self, index, value):
        self.mapping[index] = value

    def copy(self):
        dfa = DFA()
        dfa.mapping = self.mapping.copy()
        dfa.states = self.states.copy()
        dfa.accept_states = self.accept_states.copy()

        return dfa


def str_dfa(pp, dfa: DFA) -> DFA:
    """ 
    Group the chars for transition from q to p, and pretty print them.
    """

    single_transition_dfa = dfa.copy()
    single_transition_dfa.mapping.clear()

    d: defaultdict[tuple[str, str], list[str]] = defaultdict(list)

    for q, c in dfa:
        p = dfa[q, c]
        d[(q, p)].append(c)

    for q, p in d:
        internal = []
        chars = set([c for c in d[(q, p)] if isinstance(c, str)])
        nts = set([c for c in d[(q, p)] if isinstance(c, int)])
        if chars.issuperset(lowercase):
            internal.append(f"{red('a')}..{red('z')}")
            chars = chars.difference(lowercase)
        if chars.issuperset(digits):
            internal.append(f"{red('0')}..{red('9')}")
            chars = chars.difference(digits)
        elif chars.issuperset(digits_but0):
            internal.append(f"{red('1')}..{red('9')}")
            chars = chars.difference(digits_but0)

        internal += [pp(c) for c in list(chars)]
        internal += [pp(c) for c in list(nts)]
        internal_str = "|".join(internal)
        single_transition_dfa[q, internal_str] = p

    return single_transition_dfa


def print_dfa(dfa: DFA) -> None:
    info(f"=" * 20)

    Q = dfa.states
    info(f"Q is {pp(Q)}")

    accept_q = dfa.accept_states
    info(f"Acc Q is {pp(accept_q)}")

    previous_q = None
    for q, internal_str in dfa:
        p = dfa[q, internal_str]

        if q == previous_q:
            assert previous_q != None
            info(f"{' ' * len(pp(q, None))} → ({internal_str}) {pp(p, yellow)}")
        else:
            match q:
                case str():
                    info(f"{pp(q, yellow)} → ({internal_str}) {pp(p, yellow)}")
                case tuple():
                    info(
                        f"{pp(q[0], yellow)}({pp(q[1])}) → ({internal_str}) {pp(p, yellow)}")

        previous_q = q

    info(f"acc states ({len(accept_q)}): " +
         " ".join(pp(q, yellow) for q in accept_q))

    info(f"=" * 20)


def run_dfa(pp, dfa: DFA, ms):

    # NOTE - the initial state, denoted as p, is always empty string
    p = ""

    for c in ms:
        if (p, c) in dfa:
            p2 = dfa[(p, c)]
            debug(f"{pp(p)},{pp(c)} -> {pp(p2)}")
            p = p2
        else:
            p2 = p if p != () else "ε"
            debug(f"no transition at {red(p2)}, {red(c)}")
            return False

    if p not in dfa.accept_states:
        debug(f"terminated but not accpeted: {pp(p)}")
        return False
    else:
        debug(f"accpeted state: {pp(p)}")
        return True


def remove_unacceptable_states(dfa: DFA) -> None:
    """ 
    Remove the states that never transfer to an acceptance state. 
    """

    accept_states = set(dfa.accept_states)
    assert accept_states

    can_reachable_acc = accept_states.copy()
    have_new_states = True
    while have_new_states:
        have_new_states = False
        new_states = set()
        for state in can_reachable_acc:
            for q, c in dfa:
                p = dfa[q, c]
                if p == state:
                    if not (q in can_reachable_acc):
                        new_states.add(q)
                        have_new_states = True

        can_reachable_acc = can_reachable_acc.union(new_states)

    reduced_dfa = {}

    for q, c in dfa:
        p = dfa[q, c]
        if p in can_reachable_acc:
            reduced_dfa[(q, c)] = p

    dfa.mapping.clear()
    dfa.mapping.update(reduced_dfa)
    dfa.states = list(set([q for q, _ in dfa] +
                          list(dfa.mapping.values())))
    if "" not in dfa.states:
        dfa.states = [""] + dfa.states
    dfa.states.sort(key=len)


def compute_valid_strings(dfa2: DFA):
    init_state = ""

    states = dfa2.states

    valid_strings: dict[str, str] = {init_state: ""}

    dfa = defaultdict(list)
    for q, c in dfa2:
        dfa[(q, dfa2[q, c])].append(c)

    can_update = True
    while can_update:
        can_update = False

        for state in states:
            if state not in valid_strings:
                for q, p in dfa:
                    if p == state and q in valid_strings:
                        transition_symbols = dfa[(q, p)]
                        if transition_symbols:  # list is not empty
                            # we can take any symbol, let's take the first
                            symbol = transition_symbols[0]
                            # update valid string for the current state
                            valid_strings[p] = valid_strings[q] + symbol
                            can_update = True

                            break

    assert len(valid_strings) == len(states), f"{len(valid_strings)} {
        len(states)} {[s for s in states if s not in valid_strings]}"

    return valid_strings


class UDFA:
    """
    Unified DFA: `{(state1, state2): strs}` means 
        `(state1, str) -> state2` for each str in strs.
    """

    def __init__(self):
        self.mapping: dict[tuple[str, str], list[str]] = {}
        self.states: list[str] = []
        self.accept_states: list[str] = []

    def add_prefix(self, prefix) -> None:
        self.states = [prefix[:i] for i in range(
            len(prefix))] + [prefix + state for state in self.states]
        self.accept_states = [prefix + state for state in self.accept_states]
        self.mapping = {(prefix + q, prefix + p): cs for (q, p),
                        cs in self.mapping.items()}

        q = ""
        for c in prefix:
            p = q + c
            self.mapping[q, p] = [c]
            q = p

    def add_suffix(self, suffix) -> None:
        q = self.accept_states[0]
        c = suffix[0]

        p = q + c

        assert p not in self.states
        self.states.append(p)

        for state in self.accept_states:
            self.mapping[state, p] = [c]

        q = p
        for c in suffix[1:]:
            p = q + c

            assert p not in self.states
            self.states.append(p)

            self.mapping[q, p] = [c]

        self.accept_states = [p]

    def __iter__(self):
        return self.mapping.__iter__()

    def __getitem__(self, index):
        return self.mapping[index]

    def __setitem__(self, index, value):
        self.mapping[index] = value


def mfa_less(mfa1: UDFA, mfa2: UDFA) -> bool:
    """ 
    Return: True if s ∈ mfa1 => s ∈ mfa2; otherwise False.
    """

    q2q: dict[str, str] = {"": ""}

    qcp1: defaultdict[str, dict[str, str]] = defaultdict(dict)
    qcp2: defaultdict[str, dict[str, str]] = defaultdict(dict)

    debug(f"mfa1:")
    debug(pp_udfa(mfa1))
    debug(f"mfa2:")
    debug(pp_udfa(mfa2))

    for (q, p), c in sorted(mfa1.mapping.items()):
        s: str = pp(c, color=None)
        debug(f"q={q} p={p} s={s}")
        qcp1[q][s] = p

    for (q, p), c in sorted(mfa2.mapping.items()):
        s: str = pp(c, color=None)
        qcp2[q][s] = p

    new_q = deque([""])
    checked: set[str] = set([""])

    while new_q:
        q = new_q.popleft()
        if q not in q2q:
            debug(f"q={pp(q)} has no correspondence")
            return False

        q2 = q2q[q]

        for c1 in qcp1[q]:
            p1 = qcp1[q][c1]
            # NOTE - (q, c1, p1) ~ (q2, c1, qcp2[q2][c1])
            debug(f"q={q} p1={p1} c1={c1}")
            if c1 not in qcp2[q2]:
                debug(f"no transition with {pp(c1)} for {pp(q2)}")
                return False
            else:
                p2 = qcp2[q2][c1]

                if p1 in q2q:
                    if q2q[p1] != p2:
                        debug(f"{pp(q2q[p1])} != {pp(p2)}")
                        return False
                else:
                    if p2 in q2q.values():
                        return False
                    q2q[p1] = p2

                    debug(f"Add item to q2q: {pp(p1)} -> {pp(p2)}")

                if p2 not in checked:
                    new_q.append(p2)
                    checked.add(p2)

    for q in mfa1.accept_states:
        if q not in q2q or q2q[q] not in mfa2.accept_states:
            err(f"Different acc states.")
            return False

    return True


def mfa_equiv(mfa1: UDFA, mfa2: UDFA) -> bool:

    return mfa_less(mfa1, mfa2) and mfa_less(mfa2, mfa1)


def dfa2udfa(dfa: DFA) -> UDFA:
    """ Convert a DFA to a UDFA. """

    dfa = dfa.copy()
    remove_unacceptable_states(dfa)

    udfa = UDFA()
    udfa.states = dfa.states.copy()
    udfa.accept_states = dfa.accept_states.copy()

    assert udfa.accept_states

    for q, c in dfa:
        p = dfa[q, c]
        if (q, p) not in udfa:
            udfa[(q, p)] = []
        if c not in udfa[(q, p)]:
            udfa[(q, p)].append(c)

    for c in udfa.mapping.values():
        c.sort()

    return udfa


def pp_udfa(udfa: UDFA) -> str:
    """ Pretty print a UDFA. """

    pp_s = []
    for q, p in udfa:
        pp_s.append('({},{}): {},'.format(pp(q), pp(p), pp(udfa[q, p])))
    pp_s.append('states: ' + pp(udfa.states, delim=','))
    pp_s.append('acc states:' + pp(udfa.accept_states, delim=','))
    pp_s.append("end")

    return "\n".join(pp_s)


def single_str_udfa(s: str):
    """ A UDFA that only accepts a character. """

    assert len(s) == 1

    udfa = UDFA()
    udfa.mapping = {("", s): [s]}
    udfa.states = ["", s]
    udfa.accept_states = [s]

    return udfa
