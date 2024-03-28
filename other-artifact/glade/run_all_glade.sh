#!/bin/bash
mkdir glade-results

while read bench; do
	if [ ! -z "$RUN_ONLY_MICRO" ]; then
	    if [ "$bench" = "tinyc" ]; then
		    echo "Done running GLADE on all micro benchmarks; exiting now."
		    exit 0
	    fi
	fi
	if [ ! -f ${bench}-learn.log ]; then
	  ./learn_eval.sh $bench
	  echo "Done learning ${bench}"
  	else
		echo "${bench}-learn.log already exists, not going to re-run that"
  	fi
	if [ ! -f ${bench}-eval.log ]; then
	  ./precision_eval.sh $bench
	  echo "Done sampling ${bench}"
  	else
		echo "${bench}-eval.log already exists, not going to re-run that"
  	fi
	if [ ! -f ${bench}-results.asv ]; then
		./eval_mined_grammar.sh $bench
	  	echo "Done evaluating ${bench}"
	else
		echo "${bench}-results.asv already exists, not going to re-run that"
	fi
done < $HOME/bench_names
