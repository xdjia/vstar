"""
L-Star with tables implemented as numpy arrays.
"""

import numpy
from typing import Callable

from .Automata import DFA, remove_unacceptable_states


def suffixesOf(s: str):
    return list(reversed([s[i:] for i in range(len(s))] + [""]))


def prefixesOf(s: str):
    return [s[:i] for i in range(len(s))]


def find_eq(str2id, matrix, Q, q):
    """ Find representative of q in Q. """

    for eq in Q:
        if numpy.array_equal(matrix[str2id[eq]], matrix[str2id[q]]):
            return eq
    raise ValueError(f"No eq for {q}.")


def matrix2mapping(str2id, matrix, chars, Q: list[str]):
    """ 
    Convert matrix table to transitions for better efficiency. 
    """

    mapping = {}

    for q in Q:
        for c in chars:
            qc = q + c
            eq = find_eq(str2id, matrix, Q, qc)
            mapping[(q, c)] = eq

    return mapping


def learn_dfa(oracle: Callable[[str], bool],
              chars: list[str], suffixes: list[str],) -> DFA:
    """ Learn a DFA from `oracle` and given `suffixes`. """

    def add_str_id(s):
        if s in str2id:
            return str2id[s]
        i_s = len(str2id)
        str2id[s] = i_s
        id2str[i_s] = s

        return i_s

    matrix = numpy.zeros([20000, 1000])

    chars.sort()

    str2id: dict[str, int] = {}
    id2str: dict[int, str] = {}

    add_str_id("")

    for suffix in suffixes:
        add_str_id(suffix)

    for i, s1 in enumerate(sorted(str2id.keys())):
        for j, s2 in enumerate(suffixes):
            matrix[i, j] = 1 if oracle(s1 + s2) else -1

    Q: list[str] = []
    new_Q = [""]

    def close_table():

        while new_Q:
            new_q = new_Q.pop()
            i_new_q = str2id[new_q]

            if any(numpy.array_equal(matrix[str2id[q]], matrix[i_new_q]) for q in Q):
                continue

            Q.append(new_q)

            for c in chars:
                new_qc = new_q + c
                new_Q.append(new_qc)

                i_new_qc = add_str_id(new_qc)

                for j, s2 in enumerate(suffixes):
                    matrix[i_new_qc, str2id[s2]] = 1 if oracle(
                        new_qc + s2) else -1

    close_table()

    # NOTE - build DFA
    dfa = DFA()
    dfa.mapping = matrix2mapping(str2id, matrix, chars, Q)
    dfa.states = Q
    dfa.accept_states = [q for q in Q if oracle(q)]
    remove_unacceptable_states(dfa)

    return dfa
