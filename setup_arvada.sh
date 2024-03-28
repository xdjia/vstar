# copy the binaries to suitable places 
for grammar in lisp json xml while mathexpr; 
do 
    cp -f micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/parse_$grammar; 
done

# # run Arvada and print times
# for grammar in lisp json xml while mathexpr;
# do
#     echo $grammar; time python other-artifact/arvada/search.py internal micro-benchmarks/$grammar result/arvada-results/$grammar-0.log > /dev/null 2>&1
# done