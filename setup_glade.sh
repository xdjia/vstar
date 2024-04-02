# copy the binaries to suitable places 
for grammar in lisp json xml while mathexpr; 
do 
    mkdir -p other-artifact/glade/examples/$grammar/;
    cp -f micro-benchmarks/$grammar/cpp-build/file_parser other-artifact/glade/examples/$grammar/parse_$grammar
done