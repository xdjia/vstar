#!/bin/bash
mkdir $HOME/result/
mkdir $HOME/result/arvada-results

if [ $# -lt 1 ]; then
	echo "Usage: $0 ITERATION-NUM [MAX]"
	echo " runs arvada on all benchmarks, writes results to arvada-results/bench-ITERATION-NUM"
	exit 1
fi

bound=$1

if [ $# -eq 2 ]; then
	bound=$(seq $1 $2)
fi

for bench in json lisp mathexpr "while" xml; do
	for i in $bound; do
		python3 "$HOME/other-artifact/arvada/eval.py" internal $HOME/micro-benchmarks/$bench $HOME/result/arvada-results/$bench-$i.log
	done
done
