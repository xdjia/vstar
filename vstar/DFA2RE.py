from .Utils import pp
from .Automata import UDFA
from .Automata import DFA, print_dfa

from .RE import StarRE, concat, pp_re, star, alt


def udfa2re(udfa: UDFA) -> StarRE:
    """ Convert UDFA to V-Star's regular expression. """

    acc_states = udfa.accept_states
    states = sorted(udfa.states)

    assert "" in states, \
        "States must contain empty string as the initial state."

    if states[0] != "":
        states.remove("")
        states.insert(0, "")

    num_states = len(udfa.states)

    B = {}
    for i in range(num_states):
        if states[i] in acc_states:
            B[i] = ""
        else:
            B[i] = None

    A: dict[int, dict[int, StarRE]]
    A = {i: {j: None for j in range(num_states)}
         for i in range(num_states)}

    for q, p in udfa:
        t = udfa[q, p]
        # FIXME - Why is q not in states?
        i = states.index(q)
        j = states.index(p)
        A[i][j] = t

    for n in range(num_states - 1, -1, -1):
        B[n] = concat(star(A[n][n]), B[n])

        for j in range(n):
            A[n][j] = concat(star(A[n][n]), A[n][j])

        for i in range(n):
            B[i] = alt(concat(A[i][n], B[n]), B[i])
            for k in range(n):
                A[i][k] = alt(concat(A[i][n], A[n][k]), A[i][k])

    return B[0]


if __name__ == "__main__":
    dfa = DFA()

    mapping = {
        ("ε", "log(2."): ["("],
        ("ε", "l"): ["l"],
        ("l", "lo"): ["o"],
        ("lo", "log"): ["g"],
        ("log", "log1"): ["1"],
        ("log", "log("): ["("],
        ("log(", "log(2"): ["1", "2", "3", "4", "5", "6", "7", "8", "9"],
        ("log(", "log(z"): ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"],
        ("log(", "log(0"): ["0"],
        ("log(z", "log(z2"): ["1", "2", "3", "4", "5", "6", "7", "8", "9", "_"],
        ("log(z", "log(z"): ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"],
        ("log(z", "log(z,"): [","],
        ("log(z2", "log(z2"): ["1", "2", "3", "4", "5", "6", "7", "8", "9 _"],
        ("log(z2", "log(z"): ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"],
        ("log(z,", "log("): ["□"],
        ("log(2", "log(2"): ["1", "2", "3", "4", "5", "6", "7", "8", "9"],
        ("log(2", "log(z,"): [","],
        ("log(2", "log(2."): ["."],
        ("log(2.", "log(2"): ["1", "2", "3", "4", "5", "6", "7", "8", "9"],
        ("log(0", "log(z,"): [","],
        ("log(0", "log(2."): ["."],
        ("log1", "log10"): ["0"],
        ("log10", "log("): ["("], }

    acc = ['log(', 'log(2', 'log(2.']
