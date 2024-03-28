import argparse


def parse_args():
    parser = argparse.ArgumentParser(description="VStar")
    parser.add_argument("--log-level", type=str, default="CRITICAL",
                        help="Log level: DEBUG, INFO, CRITICAL.")
    parser.add_argument("--grammar", type=str, help="Grammar name.")
    parser.add_argument("--mode", type=str, default="internal", choices=[
        "internal", "external"], help="internal mode: use Python's Lark library as oracle for faster results; external mode: use call of external binaries as oracle, more practical but slower.")
    parser.add_argument("--check", type=str,
                        help="Check if a string is valid.")
    parser.add_argument("--run", type=str,
                        help="Check if a string is valid.")
    parser.add_argument("--recall", action="store_true",
                        help="Evaluate the recall of the cached learner.")
    parser.add_argument("--prec", action="store_true",
                        help="Compute the precision of the cached learner.")
    parser.add_argument("--show-grammar", action="store_true",
                        help="Print the inferred grammar.")
    parser.add_argument("--tokenize", type=str,
                        help="Tokenize a string and print the tokens.")
    parser.add_argument("--test-sampling", type=str,
                        help="Test sampling methods.")
    parser.add_argument("--tokenize-all", action="store_true",
                        help="Tokenize all seed strings and print the tokens.")
    parser.add_argument("--show-tokenizer", action="store_true",
                        help="Print the previously learned tokenizer.")
    parser.add_argument("--show-equiv-classes", action="store_true",
                        help="Print the matrices and equivalence classes of the learned VPA.")
    parser.add_argument("--show-seed-strings",
                        action="store_true", help="Print all seed strings.")
    parser.add_argument("--find-pattern", type=str,
                        help="Print the nesting pattern for the given string.")
    parser.add_argument("--renew-pattern", action="store_true",
                        default=False,
                        help="Ignore the previously generated and cached nesting patterns and regenerate them.")

    args = parser.parse_args()
    return args
