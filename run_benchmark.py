"""
Run benchmark on V-Star and print to screen the result in csv format.
The whole running time should be within an hour for "internal" mode.

Usage:
    `rm -rf result && python -O run_benchmark.py`
"""

import time
from main import eval_prec, eval_recall, infer_grammar
from vstar import logger

import argparse

from vstar.Oracle import create_oracle

parser = argparse.ArgumentParser(description="VStar")
parser.add_argument("--log-level", type=str, default="CRITICAL",
                    help="Log level: DEBUG, INFO, CRITICAL.")
parser.add_argument("--mode", type=str, default="internal", choices=[
                    "internal", "external"], help="internal mode: use Python's Lark library as oracle for faster results; external mode: use call of external binaries as oracle, more practical but slower.")


if __name__ == '__main__':
    args = parser.parse_args()
    args.name = ""  # Used for custom binary, disabled here.

    logger.setLevel("CRITICAL")
    # logger.setLevel("INFO")

    # grammars = ['lisp']
    grammars = ['json', 'lisp', 'xml', 'while', 'mathexpr']

    print(f"Grammar, Recall, Precision, F1, #Queries, " +
          f"%Q(Token), %Q(VPA), #TS, Time", flush=True)

    args.renew_pattern = True

    for grammar_name in grammars:
        args.grammar = grammar_name

        # NOTE - infer grammar and count number of membership queries
        #        for token inference and VPA learning
        start_time = time.time()
        num_q_token, num_q_all, num_ce = infer_grammar(args)
        end_time = time.time()

        recall = eval_recall(grammar_name, None)

        oracle = create_oracle(grammar_name, mode="internal")  # to compute the precision faster
        # oracle = create_oracle(grammar_name, mode=args.mode)
        prec = eval_prec(grammar_name, oracle)
        
        f1 = 2 / (1 / recall + 1 / prec)

        print(f"{grammar_name}, {recall}, {prec}, {f1}, {num_q_all}, " +
              f"{format((num_q_token / num_q_all) * 100, '.2f')}%, " +
              f"{format((1 - num_q_token / num_q_all) * 100, '.2f')}%, " +
              f"{num_ce}, " +
              f"{format(end_time - start_time, '.0f')}s", flush=True)
