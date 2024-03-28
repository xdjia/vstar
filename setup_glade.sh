# copy the binaries to suitable places 
for grammar in lisp json xml while mathexpr; 
do 
    cp -f micro-benchmarks/$grammar/cpp-build/file_parser other-artifact/glade/examples/$grammar/parse_$grammar
done

# cd ./other-artifact/glade/ 

# # run Glade and print times
# for grammar in lisp json xml while mathexpr;
# do
#     echo $grammar; time ./learn_eval.sh $grammar > /dev/null 2>&1
# done

# # cd ../../