import os
import time
from glob import glob
from tqdm import tqdm

from vstar.Oracle import Oracle
from .MatrixVStar import CE, VPALearner
from .Tokenizer import Tokenizer, expand_tokens

from .Utils import info, pp, logger


def compute_recall(grammar_name: str, oracle: Oracle,
                   vpa_learner: VPALearner, tokenizer: Tokenizer,
                   recall_test_strs: None | list[str] = None) -> tuple[float, list[CE]]:
    """ Compute the recall of the VPA hold by `vpa_learner`. 

    Returns: recall and list of counterexamples.
    """

    if not recall_test_strs:
        recall_test_strs = []
        path_to_test_strs = os.path.join(
            "micro-benchmarks", grammar_name, "test_set", '*.ex')
        info(path_to_test_strs)
        for seed_string in glob(path_to_test_strs):
            s = open(seed_string).readline().strip()
            if oracle(s):
                recall_test_strs.append(s)

    if not recall_test_strs:
        raise ValueError(f"No recall test strings found.")

    counter_examples = [expand_tokens(s, tokenizer.eagar_tokenize(s))
                        for s in recall_test_strs]

    invalid_ces: list[CE] = []
    disable_tqdm = logger.level != "CRITICAL"

    for ce in tqdm(counter_examples, disable=disable_tqdm):
        if not vpa_learner.run_vpa(ce):
            invalid_ces.append(ce)

    recall = 1.0 - len(invalid_ces) / len(recall_test_strs)

    info(f"For {grammar_name}: recall={recall}")
    info(f"For {grammar_name}: {len(invalid_ces)} invalid strings")

    invalid_ces.sort(key=lambda x: len(x[0]))
    for ce in invalid_ces[:5]:
        info(pp(ce[0]))

    return recall, invalid_ces


def compute_prec(oracle, strings: list[str]) -> tuple[float, list[str]]:
    """ Compute how many `strings` are accepted by oracle.

    Returns: precision and list of rejected strings.
    """

    info(f"len(strings)={len(strings)}")
    n = 0
    invalid_strings = []
    for s in strings:
        if oracle(s):
            n += 1
        else:
            info(pp(s))
            invalid_strings.append(s)
    prec = n / len(strings)
    info(f"prec={n}/{len(strings)}={prec}")

    return prec, invalid_strings


def collect_seed_strings(oracle, grammar_name: str) -> list[str]:
    """ Collect seed strings for micro-benchmarks. """

    seed_strings = []
    for seed_string in glob(f"micro-benchmarks/{grammar_name}/guides/*.ex"):
        s = open(seed_string).readline().strip()
        seed_strings.append(s)
        assert oracle(s)

    return sorted(seed_strings)


def collect_test_strings(oracle, grammar_name: str) -> list[str]:
    """ Collect test strings for micro-benchmarks. """

    test_strs = []

    path_test_strs = f"micro-benchmarks/{grammar_name}/test_set/*.ex"
    for seed_string in glob(path_test_strs):
        s = open(seed_string).readline().strip()
        test_strs.append(s)
        assert oracle(s)

    return test_strs


def timeit(func, *args, **kwargs):
    start_time = time.time()
    result = func(*args, **kwargs)
    end_time = time.time()
    execution_time = end_time - start_time
    print("Execution time:", execution_time, "seconds")

    return result
