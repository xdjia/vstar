# Compile the binaries for grammar recognition.

for grammar in lisp json xml while mathexpr; 
do 
    antlr4 -Dlanguage=Cpp ./micro-benchmarks/$grammar/cpp-build/*.g4 && g++ -std=c++17 -I /usr/include/antlr4-runtime -o micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/cpp-build/*.cpp -lantlr4-runtime; 
done