from vstar.MatrixVStar import load_learner
from vstar.Oracle import create_oracle

grammar_name = "lisp"
oracle = create_oracle(grammar_name, load_cache=False)

learner = load_learner(grammar_name)
learner.set_oracle(oracle)

learner.print_grammar()
