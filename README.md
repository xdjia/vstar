# V-Star Artifact

Welcome to the artifact repository for the PLDI paper #779, "V-Star: Learning Visibly Pushdown Grammars from Program Inputs." This artifact has been designed to reproduce the results presented in Table 1 of the paper.

## Option 1: Using Docker

Our results can be reproduced using a Docker image, which can be fetched by:

1. Pull the image from Docker Hub: `docker pull xdjia/vstar:latest`, or
2. Build the image locally: `docker build -t xdjia/vstar:latest .`.


### Evaluate V-Star

V-Star has two modes: in the "internal" mode, the oracle checks whether a string is valid by calling a Python parsing library. The "external" mode of V-Star, reported in our paper, calls an external binary to validate a string instead. The two modes only affect the execution time: "external" mode would be much slower.

To evaluate V-Star in the "internal" mode, run `docker run --rm xdjia/vstar:latest`.
Below shows the results of internal mode on a MacBook Air m2 with 8G memory:

|Grammar | Recall | Precision | F1 | #Queries | %Q(Token) | %Q(VPA) | #TS | Time |
| - | -: | -: | -: | -: | -: | -: | -: | -: |
| json | 1.0 | 1.0 | 1.0 | 540927 | 2.71% | 97.29% | 8043 | 117s |
| lisp | 1.0 | 1.0 | 1.0 | 16210 | 1.37% | 98.63% | 693 | 6s |
| xml | 1.0 | 1.0 | 1.0 | 207756 | 94.93% | 5.07% | 682 | 31s |
| while | 1.0 | 1.0 | 1.0 | 1439988 | 9.40% | 90.60% | 119 | 194s |
| mathexpr | 1.0 | 1.0 | 1.0 | 4961316 | 0.11% | 99.89% | 2602 | 948s |

To evaluate V-Star in the "external" mode, run `docker run --rm xdjia/vstar:latest --mode external`.


### Evaluate Glade and Arvada

In comparison, our paper reports the evaluation results of two other grammar inference tools, namely Glade and Arvada. To evaluate them, run

```shell
docker run --rm --entrypoint bash -it -v $(pwd)/result:/usr/src/vstar/result xdjia/vstar:latest -c "cd other-artifact && ./run_all.sh"
```

Below is an example output:

```
# some logging info above ...

Glade results:

Grammar & Recall & Precision & F1 & Time & #Queries
json & 0.42 & 0.98 & 0.59 & 21s & 11454
lisp & 0.23 & 1.00 & 0.38 & 7s & 3833
mathexpr & 0.18 & 0.98 & 0.31 & 42s & 19016
while & 0.01 & 1.00 & 0.02 & 13s & 9180
xml & 0.26 & 1.00 & 0.42 & 21s & 14914

Arvada results:

Grammar & Recall & Precision & F1 & Time & #Queries
json & 0.97±0.09 & 0.92±0.08 & 0.94±0.05 & 25±2s & 6784±394
lisp & 0.38±0.26 & 0.95±0.08 & 0.50±0.18 & 8±2s & 2264±307
mathexpr & 0.72±0.24 & 0.96±0.03 & 0.80±0.16 & 24±2s & 6634±421
while & 0.91±0.20 & 1.00±0.00 & 0.94±0.14 & 15±1s & 5406±563
xml & 0.99±0.02 & 1.00±0.00 & 1.00±0.01 & 61±5s & 12000±998
```

Below, we display the above results of Glade and Arvada in Markdown table:

| Glade | Recall | Precision | F1 | Time | #Queries |
| :- | -: | -: | -: | -: | -: |
| json | 0.42 | 0.98 | 0.59 | 21s | 11454 |
| lisp | 0.23 | 1.00 | 0.38 | 7s | 3833 |
| mathexpr | 0.18 | 0.98 | 0.31 | 42s | 19016 |
| while | 0.01 | 1.00 | 0.02 | 13s | 9180 |
| xml | 0.26 | 1.00 | 0.42 | 21s | 14914 |

| Arvada | Recall | Precision | F1 | Time | #Queries |
| :- | -: | -: | -: | -: | -: |
| json | 0.97±0.09 | 0.92±0.08 | 0.94±0.05 | 25±2s | 6784±394 |
| lisp | 0.38±0.26 | 0.95±0.08 | 0.50±0.18 | 8±2s | 2264±307 |
| mathexpr | 0.72±0.24 | 0.96±0.03 | 0.80±0.16 | 24±2s | 6634±421 |
| while | 0.91±0.20 | 1.00±0.00 | 0.94±0.14 | 15±1s | 5406±563 |
| xml | 0.99±0.02 | 1.00±0.00 | 1.00±0.01 | 61±5s | 12000±998 |

Results for Arvada are listed as the means over 10 runs with ± the standard deviation, adhering to the methodology outlined in Arvada's publication.

The above command takes ~1 hour on a MacBook Air m2 with 8G memory.
The results are saved under `result/`, and can be (re)printed within the host by running `sh ./display_other_eval.sh`.

That's it!

## Option 2: Build from source

To reproduce the results, follow these steps:

1. **Environment Setup**: First, set up a virtual Python (≥3.12) environment and install the V-Star library.

    ```shell
    python3 -m venv .venv
    source .venv/bin/activate
    pip install -e .
    ```

2. **Running the Benchmark**: Execute the benchmark script to generate the results. This script evaluates the V-Star algorithm across different grammars and outputs the results in CSV format.

    ```shell
    rm -rf result && python run_benchmark.py
    ```

    The benchmark execution will print results to the screen, similar to the example output below:

    ```
    Grammar, Recall, Precision, F1, #Queries, %Q(Token), %Q(VPA), #TS, Time
    json, 1.0, 1.0, 1.0, 547770, 2.67%, 97.33%, 8043, 111s
    ...
    ```

    Columns represent the grammar evaluated, recall, precision, F1 score, number of queries, percentages of queries for token inference and VPA learning, the number of test strings, and the running time for each grammar inference, respectively.

    **Note**: On an 8GB MacBook Air M2, the entire benchmark runs in under half an hour.

3. **Running the Benchmark for Execution Time**: The previous command use "internal" implementation of oracle, which means it checks whether a string is valid by calling a Python parsing library. Our paper reports the "external" mode of V-Star, which calls an external binary to validate a string instead. To count the execution time, add "--mode external":
    ```shell
    rm -rf result && python run_benchmark.py --mode external
    ```
    The results should be the same as those of the previous "internal" command except for the running time (which will be much slower). 
    
    Before running the command above, we need to use [ANTLR](https://www.antlr.org/) to compile the external binaries for checking the grammars. To install ANTLR **on macOS**, run:
    ```shell
    brew install antlr4 antlr4-cpp-runtime
    ```
    then compile the binaries as `micro-benchmarks/$grammar/cpp-build/file_parser`.
    ```shell
    for grammar in lisp json xml while mathexpr; 
    do 
        antlr -Dlanguage=Cpp ./micro-benchmarks/$grammar/cpp-build/*.g4 && g++ -std=c++17 -I /opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.1/include/antlr4-runtime -L /opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.1/lib -o micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/cpp-build/*.cpp -lantlr4-runtime; 
    done
    ```

    To install g++ and ANTLR **on GNU/Linux** like Ubuntu, run:
    ```shell
    sudo apt install g++ antlr4 libantlr4-runtime-dev
    ```
    Then, similarly but with a different ANTLR name and include path,
    ```shell
    for grammar in lisp json xml while mathexpr; 
    do 
        antlr4 -Dlanguage=Cpp ./micro-benchmarks/$grammar/cpp-build/*.g4 && g++ -std=c++17 -I /usr/include/antlr4-runtime -o micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/cpp-build/*.cpp -lantlr4-runtime; 
    done
    ```

    V-Star's external mode should now be available.
    
    **Note**: On an 8GB MacBook Air M2, the entire benchmark runs in under 15 hours.

4. **Running the Benchmark for Arvada and Glade**: In comparison, our paper reports the execution times of two other grammar inference tools, namely Glade and Arvada (but their accuracies are adopted from Arvada's paper, so only times are relevant here). To count the times, we make use of the previously compiled binaries. 

   **For Arvada**:
    ```shell
    # Reset the result directory
    rm -rf result/arvada-results/ 
    mkdir result/arvada-results/

    # copy the binaries to suitable places 
    for grammar in lisp json xml while mathexpr; 
    do 
        cp -f micro-benchmarks/$grammar/cpp-build/file_parser micro-benchmarks/$grammar/parse_$grammar; 
    done

    # run Arvada and print times
    for grammar in lisp json xml while mathexpr;
    do
        echo $grammar; time python other-artifact/arvada/search.py internal micro-benchmarks/$grammar result/arvada-results/$grammar-0.log > /dev/null 2>&1
    done
    ```
    The results should look like this:
    ```
    lisp
    python other-artifact/arvada/search.py internal micro-benchmarks/$grammar  >   3.30s user 3.27s system 58% cpu 11.180 total
    ...
    ```
    And 11.180 would be the time of Arvada for inferring the lisp grammar.

    **For Glade**:
    ```Shell
    # copy the binaries to suitable places 
    for grammar in lisp json xml while mathexpr; 
    do 
        cp -f micro-benchmarks/$grammar/cpp-build/file_parser other-artifact/glade/examples/$grammar/parse_$grammar
    done

    cd ./other-artifact/glade/ 

    # run Glade and print times
    for grammar in lisp json xml while mathexpr;
    do
        echo $grammar; time ./learn_eval.sh $grammar > /dev/null 2>&1
    done

    cd ../../
    ```
    The results should look like this:
    ```
    lisp
    ./learn_eval.sh $grammar > /dev/null 2>&1  7.03s user 6.33s system 96% cpu 13.835 total
    json    ...
    ```
    And 13.835 would be the time of Glade for inferring the lisp grammar.

    **Note**: On an 8GB MacBook Air M2, the benchmark for Arvada and Glade runs in under half an hour.

That's it!

## Advanced Usage

One can learn a tokenizer and grammar for individual grammars and adjust the verbosity for more detailed logs:

```shell
# Learn tokenizer and the grammar for 'lisp' and store them to `result/`
python main.py --log-level INFO --grammar lisp

# Tokenize a string using the inferred tokenizer
python main.py --log-level INFO --grammar lisp --tokenize "(c c)"

# Print the inferred Visibly Pushdown Grammar (VPG) to screen
python main.py --log-level INFO --grammar lisp --show-grammar

# Compute the recall for 'lisp'
python main.py --log-level INFO --grammar lisp --recall

# Compute the precision for 'lisp'
python main.py --log-level INFO --grammar lisp --prec
```

`lisp` can be replaced with `json`, `while`, `xml` and `mathexpr`; `INFO` can be replaced with `DEBUG`, or `CRITICAL` which disables logging. More information can be found in `args.py`.

## Project Structure

Here is an overview of the main components of the V-Star artifact:

- `vstar/`: Contains all source code for the V-Star algorithms.
- `micro-benchmarks/`: Hosts the datasets used for grammar learning and evaluation, organized into subdirectories for each grammar.
- `run_benchmark.py`: Serves as a script to automate the evaluation process. It wraps functions in `main.py` for inferring and evaluating grammars across the provided datasets.
- `main.py`: Acts as the main entry point for the artifact, providing detailed control over the inference and evaluation process. It allows users to specify parameters for individual grammar processing, including learning, recall, and precision computations.
- `args.py`: Defines the arguments of `main.py`.
- `result/`: Automatically generated upon running an inference, this directory stores the outcomes of the learning process, including the learner configurations and the inferred tokenizer.
- `lark-examples/`: Contains the ground-truth grammar rules for the grammars targeted by the inference process.
- `other-artifact/`: Contains artifacts of Arvada and Glade.
