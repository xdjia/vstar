"""
Run benchmark on V-Star and print to screen the result in csv format.
The whole running time should be within an hour.

Usage:
    `rm -rf result && python -O run_benchmark.py`
"""

import os
import subprocess
import time
from main import eval_prec, eval_recall, infer_grammar
from vstar import logger

import argparse

parser = argparse.ArgumentParser(description="VStar")
parser.add_argument("--log-level", type=str, default="CRITICAL",
                    help="Log level: DEBUG, INFO, CRITICAL.")
parser.add_argument("--mode", type=str, default="internal", choices=[
                    "internal", "external"], help="internal mode: use Python's Lark library as oracle for faster results; external mode: use call of external binaries as oracle, more practical but slower.")
parser.add_argument("--arvada", action="store_true", help="Evaluate Arvada.")
parser.add_argument("--glade",  action="store_true", help="Evaluate Glade.")



if __name__ == '__main__':
    grammars = ['lisp', 'json', 'xml', 'while', 'mathexpr']
    
    args = parser.parse_args()
    
    if args.arvada:
        print("== Evaluate Arvada")
        for grammar in grammars:
            command = [
                'python', 'other-artifact/arvada/search.py',
                'internal', f'micro-benchmarks/{grammar}',
                f'/usr/src/vstar/{grammar}-0.log'
            ]
            
            # Measure start time
            start_time = time.time()
            
            # Execute the command, redirecting stdout and stderr to DEVNULL
            # subprocess.run(command)
            subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


            # Measure end time and calculate elapsed time
            end_time = time.time()
            elapsed_time = end_time - start_time
            
            print(f"{grammar} time: {elapsed_time:.2f} seconds")
    
        exit(0)
        
    if args.glade:
        print("==  Evaluate Glade")
        os.chdir('./other-artifact/glade/')
        
        for grammar in grammars:
            # Construct the command to run the shell script with the current grammar
            command = ['./learn_eval.sh', grammar]
            
            # Measure start time
            start_time = time.time()
            
            # Execute the command, redirecting stdout and stderr to DEVNULL
            subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            
            # Measure end time and calculate elapsed time
            end_time = time.time()
            elapsed_time = end_time - start_time
            
            print(f"{grammar} time: {elapsed_time:.2f} seconds")
        
        exit(0)

    logger.setLevel("CRITICAL")
    # logger.setLevel("INFO")

    print(f"Grammar, Recall, Precision, F1, \\#Queries," +
          f"\\%Q(Token), \\%Q(VPA), \\#CE, Time")

    args.renew_pattern = True

    for grammar_name in grammars:
        args.grammar = grammar_name

        # NOTE - infer grammar and count number of membership queries
        #        for token inference and VPA learning
        start_time = time.time()
        num_q_token, num_q_all, num_ce = infer_grammar(args)
        end_time = time.time()

        recall = eval_recall(grammar_name)
        prec = eval_prec(grammar_name)
        f1 = 2 / (1 / recall + 1 / prec)

        print(f"{grammar_name}, {recall}, {prec}, {f1}, {num_q_all}, " +
              f"{format((num_q_token / num_q_all) * 100, '.2f')}%, " +
              f"{format((1 - num_q_token / num_q_all) * 100, '.2f')}%, " +
              f"{num_ce}, " +
              f"{format(end_time - start_time, '.0f')}s")
