# copy the binaries to suitable places 
for grammar in lisp json xml while mathexpr; 
do 
    cp -f micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/parse_$grammar; 
done