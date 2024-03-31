#!/bin/bash
if [ ! -z "${NUM_ARVADA_ITS}" ]; then
	if [ 1 -gt $NUM_ARVADA_ITS ]; then
		echo "NUM_ARVADA_ITS must be an integer greater than or equal to 1"
		exit 1
	fi
	MAX_ITS=$(($NUM_ARVADA_ITS - 1))
else
	MAX_ITS=9
fi

if [ ! -z "$RUN_ONLY_MICRO" ]; then
	echo "Note: only running microbenchmarks. Unset (i.e. set to the empty string) RUN_ONLY_MICRO if this is not the desired behavior"
fi

HOME="/usr/src/vstar"

# NOTE - Evaluate Glade
cd $HOME/other-artifact/glade && PYTHON=/usr/local/bin/python ./run_all_glade.sh
cp -r $HOME/other-artifact/glade/glade-results $HOME/result/

# NOTE - Evaluate Arvada
cd /usr/src/vstar/other-artifact

HOME=$HOME ./run_iteration_arvada.sh 0 $MAX_ITS
HOME=$HOME ./run_evaluation_arvada.sh 0 $MAX_ITS

echo "Glade results:"
echo
echo "Grammar & Recall & Precision & F1 & Time & #Queries"
for f in $HOME/result/glade-results/*.asv; 
do g=$(basename $f); echo ${g%%-*} "&" $(cat $f); done
echo

echo "Arvada results:"
echo
cd $HOME
python other-artifact/display_arvada_evaluation.py
