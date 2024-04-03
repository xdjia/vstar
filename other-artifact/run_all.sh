#!/bin/bash

set -e

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

# Check if VHOME (the root of V-Star artifact) is set
if [ -z "$VHOME" ]; then
    # VHOME not set, indicating a Docker env.
    VHOME="/usr/src/vstar"
fi

mkdir -p $VHOME/result/

# NOTE - Evaluate Glade
cd $VHOME/other-artifact/glade && PYTHON=$(which python) ./run_all_glade.sh
rm -rf $VHOME/result/glade-results
mv $VHOME/other-artifact/glade/glade-results $VHOME/result/

# NOTE - Evaluate Arvada
cd $VHOME/other-artifact

HOME=$VHOME ./run_iteration_arvada.sh 0 $MAX_ITS
HOME=$VHOME ./run_evaluation_arvada.sh 0 $MAX_ITS

cd $VHOME
sh ./display_other_eval.sh
