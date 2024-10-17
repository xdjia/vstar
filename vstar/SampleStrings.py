import random

from vstar.Token import pp_ce

from .Types import pp_alt

from .Types import GRAMMAR

from .Utils import info, pp
from .Tokenizer import Tokenizer, expand_tokens

# NOTE - a sentence is a list of chars or nonterminals;
# NOTE - a nonterminal is wrapped in a tuple.
SENTENCE = list[str | tuple[str]]


def gen_pe(grammar: GRAMMAR, L2str: dict[str, set[str]],
           max_depth: int, L: str, cur_depth=0) -> str:
    """ Sample strings that can be derived from `L` """

    if cur_depth >= max_depth:
        assert L in L2str, L
        return random.choice(list(L2str[L]))

    if L not in grammar:
        print(L, 'not in grammar:')
        for L, alts in grammar.items():
            print(f"{L} -> {' | '.join(pp_alt(alt) for alt in alts)}")
        raise ValueError

    if not grammar[L]:
        return ""

    elem = random.choice(grammar[L])
    match elem:
        case "":
            return ""
        case alt, L2:
            sL2 = gen_pe(grammar, L2str, max_depth,
                         L2, cur_depth + 1)
            sym = random.choice(alt)
            match sym:
                case str(c):
                    return c + sL2
                case (a, L1, b):
                    return a + gen_pe(grammar, L2str, max_depth,
                                      L1, cur_depth + 1) + b + sL2
                case _:
                    raise ValueError(sym)


def build_prec_strs(
    tokenizer: Tokenizer, vpa_learner,
    grammar: GRAMMAR, L2str: dict[str, set[str]],
    max_depth=10, num_to_sample=1000
) -> list[str]:
    """ Sample strings from the learner's VPA. """
    start_nt = "m0_L0"  # Always this one

    sampled_strings: list[str] = []

    MAX_ITERATION = 1000
    num_iteration = 0
    while len(sampled_strings) < num_to_sample:
        num_iteration += 1
        if num_iteration == MAX_ITERATION:
            # raise RuntimeError("Iteration limit reached.")
            break

        s = gen_pe(grammar, L2str, max_depth, start_nt, 0)
        # print('sampled:', s)
        token_seq = tokenizer.eagar_tokenize("".join(s))
        ts = expand_tokens("".join(s), token_seq)
        if vpa_learner.run_vpa(ts):
            info(pp(s))
            sampled_strings.append(s)
        else:
            info(pp(s))
            print(pp_ce(ts))

    # print(sampled_strings)
    # exit()

    return sampled_strings
