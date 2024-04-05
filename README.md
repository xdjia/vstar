# V-Star Artifact

Welcome to the artifact repository for the PLDI paper #779, "V-Star: Learning Visibly Pushdown Grammars from Program Inputs." This artifact has been designed to reproduce the results presented in Table 1 of the paper.

V-Star has two modes: in the "internal" mode, the oracle validates a string by calling a Python parsing library ([Lark](https://github.com/lark-parser/lark)). In the "external" mode of V-Star, reported in our paper, the oracle calls an external binary to validate a string. The two modes only affect the execution time: "external" mode would be much slower.

## Option 1: Using Docker

### Getting Started

Our results can be reproduced using a Docker image, which can be fetched by:

1. Pull the image from Docker Hub: `docker pull xdjia/vstar:latest`, or
2. Build the image locally: `docker build -t xdjia/vstar:latest .`.

### Step-by-Step Instructions

#### Evaluate V-Star

To evaluate V-Star in the "internal" mode, run 
```shell
docker run --rm xdjia/vstar:latest
```
Below shows the results of internal mode on a MacBook Air m2 with 8G memory:

|Grammar | Recall | Precision | F1 | #Queries | %Q(Token) | %Q(VPA) | #TS | Time |
| - | -: | -: | -: | -: | -: | -: | -: | -: |
| json | 1.0 | 1.0 | 1.0 | 540927 | 2.71% | 97.29% | 8043 | 117s |
| lisp | 1.0 | 1.0 | 1.0 | 16210 | 1.37% | 98.63% | 693 | 6s |
| xml | 1.0 | 1.0 | 1.0 | 207756 | 94.93% | 5.07% | 682 | 31s |
| while | 1.0 | 1.0 | 1.0 | 1439988 | 9.40% | 90.60% | 119 | 194s |
| mathexpr | 1.0 | 1.0 | 1.0 | 4961316 | 0.11% | 99.89% | 2602 | 948s |

Columns represent the grammar evaluated, recall, precision, F1 score, number of queries, percentages of queries for token inference and VPA learning, the number of test strings, and the running time for each grammar inference, respectively.

To evaluate V-Star in the "external" mode, run 
```shell
docker run --rm xdjia/vstar:latest --mode external
```


#### Evaluate Glade and Arvada

In comparison, our paper reports the evaluation results of two other grammar inference tools, namely Glade and Arvada. To evaluate them, run

```shell
docker run --rm --entrypoint bash -it -v $(pwd)/result:/usr/src/vstar/result xdjia/vstar:latest -c "./other-artifact/run_all.sh"
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
The results are saved under `result/`, and can be (re)printed within the host by running `sh ./display_other_eval.sh`. Feel free to remove `result/`.

## Option 2: Build from Source

### Getting Started

First, set up a virtual Python (≥3.12) environment and install the V-Star library.

```shell
python3 -m venv .venv
source .venv/bin/activate
pip install -e .
```

Then, build the binaries using [ANTLR](https://www.antlr.org/).  
1. To install ANTLR on **macOS**, run:
    ```shell
    brew install antlr4 antlr4-cpp-runtime
    ```
2. To install ANTLR (and g++) on **GNU/Linux** like Ubuntu, run:
    ```shell
    sudo apt install g++ antlr4 libantlr4-runtime-dev
    ```

Finally, compile the needed binaries and put them to locations specified by Arvada and Glade:
```shell
VHOME=$(pwd) zsh ./setup_bin.sh
zsh ./setup_arvada.sh
zsh ./setup_glade.sh
```

### Step-by-Step Instructions

#### Evaluate V-Star

Evaluate the "internal" mode of V-Star:

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

Count the execution time of the "external" mode of V-Star:
```shell
rm -rf result && python run_benchmark.py --mode external
```
The results should be the same as those of the previous "internal" command except for the running time (which will be much slower). 

**Note**: On an 8GB MacBook Air M2, the entire benchmark runs in under 15 hours.

#### Evaluate Glade and Arvada

In comparison, our paper reports the results of two other grammar inference tools, namely Glade and Arvada. To evaluate them, run
```shell
VHOME=$(pwd) other-artifact/run_all.sh
```

Finally, we note that all generated results are stored under `result/`. Free free to delete it.

## A Note of the External Mode

We need to clarify an issue with the "external" mode evaluation. The recall for `mathexpr` is 0.999, not 1.0, because V-Star rejects a specific string in the recall dataset. We call this string S-744, since it is contained in `micro-benchmarks/mathexpr/cpp-build/test_set/test-744.ex`. 

However, this is not a mistake. V-Star correctly identifies S-744 as invalid, just as the oracle binary does, so the true recall accuracy remains 1.0.

The presence of S-744 in the recall dataset, which should only contain valid strings, puzzled us at first. We traced the issue back to the dataset's origin in Arvada's artifact. 

As mentioned in README, there are two modes: "internal" mode uses an internal Python library to recognize string, and we note that the library, Lark, uses a Lark grammar file; "external" mode uses an external binary, which is compiled from an ANTLR grammar file. The two grammar files reside at `lark-examples/mathexpr.lark` and `micro-benchmarks/mathexpr/cpp-build/g_mathexpr.g4`, respectively.

Although the two grammar files should be (and indeed look like) the same, they actually specify different grammars. This is due to the following rule in `mathexpr`:

`exprp: SPACE op SPACE expr exprp |;`

Notice that the vertical bar `|` is not followed by any rules, which intuitively suggests that `exprp` can represent an empty string. Lark interprets it this way, but ANTLR doesn't. Consequently, S-744, which relies on this interpretation, is accepted by Lark but rejected by ANTLR.

Therefore, we guess that Arvada generated the recall dataset using the Lark grammar, but the evaluation was conducted using the ANTLR grammar.

## How to Use

### Natively Supported Grammars

Some grammar are supported by V-Star natively, including `json`, `while`, `xml` and `mathexpr`. To learn them, run
```shell
# Learn tokenizer and grammar for 'lisp' and store them to `result/`
python main.py --log-level INFO --grammar lisp --renew-pattern
```

Other usages of V-Star:

```shell
# Check if a string is valid
python main.py --log-level INFO --grammar lisp --check "(c c)"

# Tokenize a string using the inferred tokenizer
python main.py --log-level INFO --grammar lisp --tokenize "(c c)"

# Print the inferred Visibly Pushdown Grammar (VPG) to screen
python main.py --log-level INFO --grammar lisp --show-grammar

# Compute the recall for 'lisp'
python main.py --log-level INFO --grammar lisp --recall

# Compute the precision for 'lisp'
python main.py --log-level INFO --grammar lisp --prec
```

More information can be found in `args.py`.

### Custom Binaries

#### Provide Your Binaries to V-Star

First, please provide a script that wraps custom binary, e.g., `run_my_binary.sh`, so that the command
```shell
run_my_binary.sh ./a_file_containing_a_string
```
exits with either 1, meaning the string is invalid, or 0, meaning the string is valid. 

As an example, this artifact contains a script `run_my_lisp.sh` that makes use of the lisp binary built for the external mode:

```shell
#!/bin/bash

# Usage: run_my_lisp.sh <filename>

filename=$1
micro-benchmarks/lisp/parse_lisp $filename
result=$?
exit $result
```

Please make this script executable:
```shell
chmod +x ./run_my_lisp.sh
```

#### Run V-Star

Please provide the path to the script, a name of the oracle, and the path to the seed string directory:
```
python main.py --log-level INFO --oracle <path_to_script.sh> --name <my_binary> --seeds <path_to_my_seeds> --renew-pattern
```

Continuing our example, the command would be:

```shell
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --seeds $(pwd)/micro-benchmarks/lisp/guides --renew-pattern
```

Here are some other usages of V-Star:

```shell
# Check if a string is valid
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --check "(c c)"

# Tokenize a string using the inferred tokenizer
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --tokenize "(c c)"

# Print the inferred Visibly Pushdown Grammar (VPG) to screen
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --show-grammar

# Compute the recall for 'my_lisp'
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --recall --recall-dataset micro-benchmarks/lisp/test_set/

# Compute the precision for 'my_lisp'
python main.py --log-level INFO --oracle $(pwd)/run_my_lisp.sh --name my_lisp --prec
```

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
