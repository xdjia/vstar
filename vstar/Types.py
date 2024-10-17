from collections import defaultdict
from typing import Callable, Literal, Union
from .Utils import pp, debug
from .Utils import info, lowercase, uppercase, digits


from .Colors import blue
art_call = "‹"
art_retn = "›"


# NOTE - a token is either a char, or (aqb, <aqb>)
TOKEN = str | tuple[str, tuple[str, str, str]]
# NOTE - module index and nonterminal index
MOD_NT = tuple[int, int]
# NOTE - MOD_NT and access word
MOD_NT_ACC = tuple[MOD_NT, str]

M_TERMINAL = str | tuple[str, str, str]
M_TERMINALs = list[M_TERMINAL]

ALT = Literal[""] | tuple[M_TERMINALs, str]

ALTs = list[ALT]

# NOTE - Compact VPG forms {L: [cs, L1] }, where cs:
#        list[str | tuple[str, str, str]] is terminal sequence.
GRAMMAR = dict[str, ALTs]

IGRAMMAR = dict[int, dict[str, ALTs]]


# NOTE - merged alternatives
MALT = str | tuple[str, MOD_NT_ACC, str]

# NOTE - merged VPGs
MGRAMMAR = dict[int,
                defaultdict[tuple[MOD_NT_ACC, MOD_NT_ACC],
                            list[MALT]]]


def pp_cs(cs: M_TERMINALs):
    """ Pretty print terminal sequences. """

    pp_s = []
    for c in cs:
        match c:
            case str(c):
                pp_s.append(pp(c))
            case (a, L, b):
                pp_s.append(f"{art_call}{pp(a)}{L}{pp(b)}{art_retn}")

    return "".join(pp_s)


def pp_alt(alt: ALT):
    """ Pretty print rule alternative. """

    match alt:
        case "":
            return pp("")
        case (cs, L):
            return f"{pp_cs(cs)} {L}"


def pp_cxt(cxt: tuple[str, str]):
    """ pretty print contexts """

    return f"({pp(cxt[0])},{pp(cxt[1])})"


def pp_nt(nt: tuple[int, int]):
    """ pretty print nonterminals """

    return pp(f"m{nt[0]}_{nt[1]}", color=blue)


def pp_grammar(grammar: GRAMMAR):
    s = []
    for L, alts in grammar.items():
        s.append(pp(L) + ' -> ' + ' | '.join(pp_alt(alt) for alt in alts))

    return '\n'.join(s)


def print_grammar(grammar: GRAMMAR):
    # NOTE - print grammar info
    print(pp_grammar(grammar))
