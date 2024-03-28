import os
import time
import string
from typing import Callable

from vstar import logger
from .Colors import red
from .Nonterminal import L2name
from .Colors import light_yellow, red, blue


path_to_result = "result"
if not os.path.exists(path_to_result):
    os.mkdir(path_to_result)

f_color = None | Callable[[str], str]

art_call = "‹"
art_retn = "›"

lowercase = list(string.ascii_lowercase)
uppercase = list(string.ascii_uppercase)

digits = list([f"{i}" for i in range(10)])
digits_but0 = list([f"{i}" for i in range(1, 10)])

err = logger.error
info = logger.info
debug = logger.debug
warning = logger.warning
critical = logger.critical

def loop_with_timeout(iterable, timeout):
    start_time = time.time()
    for item in iterable:
        if time.time() - start_time > timeout:
            err("Timeout exceeded")
            break
        yield item


def add(l: list, x):
    if x not in l:
        l.append(x)


def remove_duplicates_keep_order(seq):
    seen = set()
    seen_add = seen.add
    return [x for x in seq if not (x in seen or seen_add(x))]


def _pps(s: str, color: f_color = red):
    """ Pretty print a character. """

    match s:
        case "":
            if color:
                return light_yellow("ε")
            return ""
        case _:
            if color:
                s = s.replace(" ", "□")
                s = color(s)
            return s


def _pp_nt(name: str, color: f_color = red):
    """ Pretty print a nonterminal. """
    
    if not color:
        return name

    if name == "ee":
        name = "ε"

    return blue(name)


def pp(s: str | int | tuple | list,
       color: f_color = red,
       nt2name: None | L2name = None,
       delim: str = " "):
    """ Pretty print different V-Star objects. """
    
    match s:
        case str():
            return _pps(s, color)
        case int():
            name = str(s)
            if nt2name:
                name = nt2name[s]
            return _pp_nt(name, color)
        case tuple():
            s = [pp(c, color) for c in s]

            pp_s = "".join(s)

            if pp_s == "":
                if color:
                    return color("ε")
                else:
                    return ""

            return pp_s
        case list():
            return delim.join(pp(ms, color) for ms in s)
