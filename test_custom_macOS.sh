set -e

# Setup binary
VHOME=$(pwd) zsh ./setup_bin.sh
zsh ./setup_arvada.sh
zsh ./setup_glade.sh

# Learn my_lisp
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --seeds $(pwd)/micro-benchmarks/lisp/guides --renew-pattern

# Check if a string is valid
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --check "(c c)"

# Tokenize a string using the inferred tokenizer
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --tokenize "(c c)"

# Print the inferred Visibly Pushdown Grammar (VPG) to screen
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --show-grammar

# Compute the recall for 'my_lisp'
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --recall --recall-dataset micro-benchmarks/lisp/test_set/

# Compute the precision for 'my_lisp'
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --prec