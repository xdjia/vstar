from typing import Callable, Any, Literal
from .Utils import info, debug, critical
import subprocess
import tempfile

from lark.lark import Lark

from collections import defaultdict

import os
import time
import pickle


# NOTE - internal mode: use Python's Lark library as oracle for faster results
# NOTE - external mode: use call of external binaries as oracle, more practical but slower
MODE = Literal["internal"] | Literal["external"]


lark_grammars = ["json", "lisp", "xml", "while", "mathexpr"]

parser = {
    g: Lark(open(f"lark-examples/{g}.lark", encoding="utf8").read())
    for g in lark_grammars
}


class Oracle:
    def __init__(self, name: str, oracle, mode:MODE='internal') -> None:
        self.name = name
        self.oracle: Callable[[str], bool] = oracle
        self.cache: dict[str, bool] = {}
        self.time_spent = 0.0
        self.try_checks = 0
        self.command = f'micro-benchmarks/{name}/cpp-build/file_parser'

        match mode:
            case "internal":
                self._oracle = self.oracle
            case "external":
                self._oracle = self._parse_external
                
                # def _oracle(s:str):
                #     result = self._parse_external(s)
                #     if result != self.oracle(s):
                #         print(f"Error: {s} {result} {self.oracle(s)}")
                #         exit(1)
                #     return result
                
                # self._oracle = _oracle
        
    def _parse_external(self, s:str, timeout = 3):
        """
        Does the work of calling the subprocess.
        """
        FNULL = open(os.devnull, 'w')
        f = tempfile.NamedTemporaryFile()
        f.write(bytes(s, 'utf-8'))
        f_name = f.name
        f.flush()
        try:
            # With check = True, throws a CalledProcessError if the exit code is non-zero
            subprocess.run([self.command, f_name], stdout=FNULL, stderr=FNULL, timeout=timeout, check=True)
            f.close()
            FNULL.close()
            return True
        except subprocess.CalledProcessError as e:
            f.close()
            FNULL.close()
            return False
        except subprocess.TimeoutExpired as e:
            print(f"Caused timeout: {s}")
            f.close()
            FNULL.close()
            return True
        

    def __call__(self, s) -> Any:
        self.try_checks += 1
        if s in self.cache:
            return self.cache[s]

        start_time = time.time()

        res = self._oracle(s)

        self.time_spent += time.time() - start_time

        self.cache[s] = res
        return res

    def reset(self):
        self.cache = defaultdict(lambda: False)

    def print_info(self):
        info(f"total query: {self.try_checks} " +
             f"real query: {len(self.cache)} " +
             f"valid: {len([s for s in self.cache if self.cache[s]])} " +
             f"oracle time={'{:.2f}'.format(self.time_spent)}")

        return len(self.cache)

    def print_strings(self):
        valid_ss = [s for s in self.cache if self.cache[s]]
        valid_ss.sort()
        for s in valid_ss:
            info(s)


def lark_oracle(name):
    p = parser[name]

    def _oracle(s: str) -> bool:
        try:
            p.parse(s)
            return True
        except:
            return False

    return _oracle


def load_oracle_cache(name: str):
    path = f"{name}.oracle.pickle"
    if os.path.exists(path):
        with open(path, "rb") as f:
            checked: dict[str, bool] = pickle.load(f)
    else:
        checked = {}

    return checked


def create_oracle(name: str, load_cache=False, 
                  mode:MODE="internal") -> Oracle:

    oracle = Oracle(name, lark_oracle(name), mode=mode)
    if load_cache:
        oracle.cache = load_oracle_cache(name)
        info(f"{len(oracle.cache)} cached strings.")

    if name in lark_grammars:
        info("Use Lark grammar.")
        return oracle

    raise ValueError("Unknown grammar name.")


if __name__ == "__main__":
    pass
