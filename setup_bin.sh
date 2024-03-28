# Compile the binaries for grammar recognition.

for grammar in lisp json xml while mathexpr; 
do 
    antlr4 -Dlanguage=Cpp /usr/src/vstar/micro-benchmarks/$grammar/cpp-build/*.g4 && g++ -std=c++17 -I /usr/include/antlr4-runtime -o /usr/src/vstar/micro-benchmarks/$grammar/cpp-build/file_parser /usr/src/vstar/micro-benchmarks/$grammar/cpp-build/*.cpp -lantlr4-runtime; 
done