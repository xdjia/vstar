import random

from .Utils import info, pp
from .MatrixVStar import GRAMMAR, VPALearner
from .Tokenizer import Tokenizer, expand_tokens

# NOTE - a sentence is a list of chars or nonterminals;
# NOTE - a nonterminal is wrapped in a tuple.
SENTENCE = list[str | tuple[str]]

def gen_pe(grammar: GRAMMAR, L2str: dict[str, list[str]],
           L2eps:set[str], max_depth: int, L: str, cur_depth=0) -> str:
    """ Sample strings that can be derived from `L` """

    if cur_depth >= max_depth:
        assert L in L2str and L2str[L], L                
        return random.choice(L2str[L])

    res = ""

    if not grammar[L]:
        if L in L2eps:
            return ""
        
    alt, L2 = random.choice(grammar[L])
    sL2 = gen_pe(grammar, L2str, L2eps,max_depth,
                 L2, cur_depth + 1)
    for sym in alt:
        match sym:
            case str(c):
                res = c + sL2
            case (a, L1, b):
                res += a + gen_pe(grammar, L2str,L2eps, max_depth,
                                  L1, cur_depth + 1) + b + sL2
            case _:
                raise ValueError(sym)

    return res


def build_prec_strs(
    tokenizer: Tokenizer, vpa_learner: VPALearner,
    grammar: GRAMMAR, L2eps: set[str], L2str: dict[str, list[str]],
    max_depth=20, num_to_sample=1000
) -> list[str]:
    """ Sample strings from the learner's VPA. """
    start_nt = "m0_L0"  # Always this one

    sampled_strings: list[str] = []

    MAX_ITERATION = 10000
    num_iteration = 0
    while len(sampled_strings) < num_to_sample:
        num_iteration += 1
        if num_iteration == MAX_ITERATION:
            raise RuntimeError("Iteration limit reached.")

        s = gen_pe(grammar, L2str, L2eps, max_depth, start_nt, 0)
        if vpa_learner.run_vpa(expand_tokens(
                "".join(s), tokenizer.eagar_tokenize("".join(s)))):
            info(pp(s))
            sampled_strings.append(s)
        else:
            info(pp(s))

    return sampled_strings