#!/bin/sh

# Compile the binaries for grammar recognition.

# Check if VHOME (the root of V-Star artifact) is set
if [ -z "$VHOME" ]; then
    # VHOME not set, indicating a Docker env.
    VHOME="/usr/src/vstar"
fi

OS="$(uname -s)"

case "$OS" in
  Darwin)
    echo "Running on macOS."
    # macOS-specific commands here
    for grammar in lisp json xml while mathexpr; 
    do 
        antlr -Dlanguage=Cpp ./micro-benchmarks/$grammar/cpp-build/*.g4 && g++ -std=c++17 -I /opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.1/include/antlr4-runtime -L /opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.1/lib -o micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/cpp-build/*.cpp -lantlr4-runtime; 
    done
    ;;

  Linux)
    echo "Running on Linux."
    for grammar in lisp json xml while mathexpr; 
    do 
        antlr4 -Dlanguage=Cpp $VHOME/micro-benchmarks/$grammar/cpp-build/*.g4 && g++ -std=c++17 -I /usr/include/antlr4-runtime -o $VHOME/micro-benchmarks/$grammar/cpp-build/file_parser $VHOME/micro-benchmarks/$grammar/cpp-build/*.cpp -lantlr4-runtime; 
    done
    ;;

  *)
    echo "Unsupported operating system: $OS"
    ;;
esac


