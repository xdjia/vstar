#!/bin/bash

# Usage: run_my_lisp.sh <filename>

filename=$1
micro-benchmarks/lisp/parse_lisp $filename
result=$?
exit $result