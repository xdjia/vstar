import os
import tqdm as tqdm

from args import parse_args

import vstar.Eval as Eval
from vstar.Oracle import MODE, Oracle, create_oracle
from vstar import SampleStrings, logger
from vstar.Utils import info, lowercase, pp, uppercase, digits
from vstar.NestingPattern import find_all_pattern, find_pattern
from vstar.MatrixVStar import build_L2str, learn_vpa, load_learner
from vstar.Tokenizer import learn_tokenizer, load_tokenizer, tokenize_string
from vstar.Types import print_grammar


def eval_recall(name: str, path_recalls:None|str):
    tokenizer = load_tokenizer(name)
    vpa_learner = load_learner(name)
    recall, _ = Eval.compute_recall(
        name, vpa_learner, tokenizer, path_recalls)

    return recall


def eval_prec(grammar_name: str, oracle:Oracle):
    vpa_learner = load_learner(grammar_name)
    vpa_learner.set_oracle(oracle)
    grammar, L2eps = vpa_learner.vpa2vpg()

    for L in grammar:
        if not grammar[L] and L not in L2eps:
            info(L)
            raise ValueError

    L2str = build_L2str(grammar, L2eps)

    tokenizer = load_tokenizer(grammar_name)
    sampled_strings = SampleStrings.build_prec_strs(
        tokenizer, vpa_learner, grammar, L2eps, L2str)
    # sampled_strings = SampleStrings.build_prec_strs(
    #     tokenizer, vpa_learner, grammar, L2eps)
    prec, _ = Eval.compute_prec(oracle, sampled_strings)

    return prec


def infer_grammar(args):

    # NOTE - create oracle
    if args.name:
        oracle = create_oracle(args.name, mode="custom",
                               binary_path=args.oracle, load_cache=False)
    else:
        oracle = create_oracle(args.grammar, mode=args.mode, load_cache=False)

    # NOTE - collect data
    if args.name:
        seeds_path = os.path.join(args.seeds, "*")
    else:
        seeds_path = f"micro-benchmarks/{args.grammar}/guides/*.txt"
        
    seed_strings = Eval.collect_seed_strings(oracle, seeds_path)
    
    assert seed_strings, "Error: No seed strings"
    
    # NOTE - identify nesting patterns
    intervalDict = find_all_pattern(
        oracle, seed_strings, renew_pattern=args.renew_pattern)
    
    pln_strings = [s for s in seed_strings
                   if s not in intervalDict]

    # NOTE - All chars
    chars = list(set(c for s in seed_strings for c in s).union(
        lowercase + uppercase + digits))
    chars.sort()

    (tokenizer, cr2crs, cr2cxt, extra_valid_strs, plain_valid_strs) = \
        learn_tokenizer(oracle, intervalDict, pln_strings, chars)

    info("After #Q(Token) ")

    # NOTE - Number of membership queries used for token inference
    num_queries_token = oracle.print_info()

    vpa_learner, num_ce = learn_vpa(
        oracle,
        tokenizer,
        chars,
        cr2cxt,
        seed_strings,
        pln_strings,
        extra_valid_strs,
        plain_valid_strs)

    info("After #Q(VPA) ")
    # NOTE - Number of all membership queries
    num_queries_all = oracle.print_info()

    vpa_learner.consolidate_vpa()
    vpa_learner.dump_learner()

    return num_queries_token, num_queries_all, num_ce


def main():

    args = parse_args()

    if args.log_level:  # DEBUG, INFO, ERROR
        logger.setLevel(args.log_level)
        
    # NOTE - create oracle
    if args.name:
        print("Custom oracle")
        oracle = create_oracle(args.name, mode="custom",
                               binary_path=args.oracle, load_cache=False)
    else:
        oracle = create_oracle(args.grammar, load_cache=False, mode=args.mode)

    # NOTE - Evaluate the precision of the cached learner.
    if args.prec:
        if args.name:
            eval_prec(args.name, oracle=oracle)
        else:
            eval_prec(args.grammar, oracle=oracle)
        exit()

    # NOTE - Evaluate the recall of the cached learner.
    if args.recall:
        if args.name:
            eval_recall(args.name, path_recalls=args.recall_dataset)
        else:
            eval_recall(args.grammar, path_recalls=None)
        exit()

    if args.check:
        print(f'𝒪({pp(args.check)})={oracle(args.check)}')
        exit()

    # NOTE - Tokenize given string.
    if args.tokenize:
        tokenize_string(oracle.name, args.tokenize)
        exit()

    # NOTE - Tokenize all seed strings.
    if args.tokenize_all:
        for s in Eval.collect_seed_strings(oracle, oracle.name):
            tokenize_string(oracle.name, s)
        exit()

    # NOTE - Show seed strings.
    if args.show_seed_strings:
        seed_strings = Eval.collect_seed_strings(oracle, oracle.name)
        for i, s in enumerate(seed_strings):
            info(f"seed string {i + 1}/{len(seed_strings)}: " + pp(s))
        exit()

    # NOTE - Show tokenizer.
    if args.show_tokenizer:
        tokenizer = load_tokenizer(oracle.name)
        info(tokenizer)
        exit()

    # NOTE - Print the matrices and equivalence classes of the learned VPA.
    if args.show_equiv_classes:
        vpa_learner = load_learner(oracle.name)
        for module, Q in enumerate(vpa_learner.Qs):
            info(f"M{module} reprs ({len(Q)}): {pp(Q)}")

        for module in range(vpa_learner.n_classes):
            info(vpa_learner.pp_cxt(module))

        vpa_learner.print_matrix_info()
        exit()

    # NOTE - Run VPA on given string.
    if args.run:
        ce = tokenize_string(oracle.name, args.run)
        vpa_learner = load_learner(oracle.name)
        vpa_learner.set_oracle(oracle)
        # vpa_learner.print_matrix_info()
        # vpa_learner.print_mm_transitions()
        info(vpa_learner.pp_cxt(1))

        vpa_learner.break_counterexample(ce)
        info(f"run_vpa: {vpa_learner.run_vpa(ce)}")
        exit()

    # NOTE - Find nesting pattern for given string.
    if args.find_pattern:
        find_pattern(oracle, args.find_pattern)
        exit()

    # NOTE - Test the sampling methods.
    if args.test_sampling:
        s = args.test_sampling
        ce = tokenize_string(oracle.name, s)

        tokenizer = load_tokenizer(oracle.name)
        vpa_learner = load_learner(oracle.name)
        vpa_learner.set_oracle(oracle)  # Remember to set oracle

        grammar, L2eps = vpa_learner.vpa2vpg()
        print_grammar(grammar)
        info(pp(list(L2eps), delim=','))

        for L in L2eps:
            if L not in grammar:
                info(pp(L))

        exit()

    # NOTE - Convert VPA to a VPG.
    if args.show_grammar:
        vpa_learner = load_learner(oracle.name)
        vpa_learner.set_oracle(oracle)  # Remember to set oracle
        grammar, L2eps = vpa_learner.vpa2vpg()

        print_grammar(grammar)

        # remove_redundant_rules(grammar)
        exit()

    infer_grammar(args)


if __name__ == '__main__':
    main()
