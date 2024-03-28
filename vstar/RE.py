import re
from typing import Union
from itertools import combinations

from .Utils import pp
from .Colors import cyan, red
from .Utils import lowercase, info, uppercase, digits, debug

# NOTE - V-Star's Regular expression.
# NOTE - `tuple`: concatenation; `list`: alternation.
StarRE = Union[None, str, tuple, list, "Opt", "Plus", "Star"]


class Opt:
    """ Optional: r=(...)? """

    def __init__(self, q: StarRE) -> None:
        self.q = q


class Plus:
    """ One or more: r=(...)+ """

    def __init__(self, q: StarRE) -> None:
        self.q = q


class Star:
    """ Optional or Plus r=(...)* """

    def __init__(self, q: StarRE) -> None:
        self.q = q


def eq_re(r1: StarRE, r2: StarRE):
    return pp_re(r1, []) == pp_re(r2, [])


def star(r: StarRE) -> StarRE:
    if r is None:
        return ""
    else:
        return Star(r)


def concat(r1: StarRE, r2: StarRE) -> StarRE:
    """ r <- r1 r2 """

    if r1 is None or r2 is None:
        return None

    if r1 == "":
        return r2
    if r2 == "":
        return r1

    match r1, r2:
        case tuple(), tuple():
            r = r1 + r2
        case tuple(), _:
            r = (*r1, r2)
        case _, tuple():
            r = (r1, *r2)
        case _, _:
            r = (r1, r2)

    # NOTE - Merge aa* and a*a to a+
    debug(f"before concat {pp_re(r, all_chars=[])}")
    i = 0
    while i < len(r):
        ra = r[i]

        if isinstance(ra, Star):
            merged = False

            for j in range(i):
                rb = r[j:i]
                if eq_re(rb, ra.q):
                    r = r[:j] + (Plus(ra.q),) + r[i + 1:]
                    merged = True
                    i = j + 1
                    break

            if not merged:
                for j in range(i + 2, len(r) + 1):
                    rb = r[i + 1:j]
                    if eq_re(rb, ra.q):
                        r = r[:i] + (Plus(ra.q),) + r[j:]
                        merged = True
                        i += 1
                        break

            if merged:
                continue

        i += 1

    debug(f"after concat {pp_re(r, all_chars=[])}")

    if len(r) == 1:
        return r[0]

    return r


def merge_alt(r):
    """ Merge [r1 r, r2 r] to [(r1|r2) r] """

    updating = True
    while updating:
        updating = False

        for c1, c2 in combinations(r, 2):
            t = []
            if isinstance(c1, tuple) and isinstance(c2, tuple):
                for t1, t2 in zip(reversed(c1), reversed(c2)):
                    if eq_re(t1, t2):
                        t.append(t1)
                    else:
                        break

                if t:
                    t.reverse()
                    p1 = c1[: -len(t)]
                    p2 = c2[: -len(t)]

                    if len(p1) == 1:
                        p1 = p1[0]
                    if len(p2) == 1:
                        p2 = p2[0]

                    r += [((alt(p1, p2,), *t))]
                    r.remove(c1)
                    r.remove(c2)
                    updating = True
                    break

                else:
                    t = []
                    for t1, t2 in zip(c1, c2):
                        if eq_re(t1, t2):
                            t.append(t1)
                        else:
                            break

                    if t:
                        p1 = c1[len(t):]
                        p2 = c2[len(t):]
                        if len(p1) == 1:
                            p1 = p1[0]
                        if len(p2) == 1:
                            p2 = p2[0]

                        r += [(*t, (alt(p1, p2,)))]
                        r.remove(c1)
                        r.remove(c2)
                        updating = True
                        break

    if len(r) == 0:
        return ""

    if len(r) == 1:
        return r[0]

    if len(r) == 2:
        if r[0] == "":
            return r[1]
        if r[1] == "":
            return r[0]

    return r


def alt(r1, r2):
    """ r <- (r1|r2) """

    if r1 in [None, tuple()]:
        return r2
    if r2 in [None, tuple()]:
        return r1

    match r1, r2:
        case list(), list():
            r = r1 + r2
        case list(), _:
            r = [*r1, r2]
        case _, list():
            r = [r1, *r2]
        case _, _:
            r = [r1, r2]

    def remove_dup(r):
        r3 = []
        for c in r:
            if c not in r3:
                r3 += [c]
        return r3

    r = remove_dup(r)

    o = True
    debug(f"compare merge alt before {r}")
    assert o
    merge_alt(r)
    debug(f"compare merge alt after  {r}")

    if len(r) == 0:
        return ""

    if len(r) == 1:
        return r[0]

    return r


def group_chars(all_chars: list[str], chars: list[str]) -> list[str]:
    """
    Group and pretty print chars in regular expression.
    """

    assert chars, "Empty char set."
    assert "" not in chars, "ε cannot be transition symbol."
    assert all(len(c) == 1 for c in all_chars
               ), "`all_chars` should only contain characters."
    assert all(
        len(c) == 1 for c in chars), "`chars` should only contain characters."

    if len(chars) == len(all_chars):
        return ["<Any>"]

    template_chars_list = [lowercase, uppercase, digits]
    other_chars = [c for c in all_chars if all(
        c not in l for l in template_chars_list)]
    template_chars_list.append(other_chars)

    color_for_special = cyan

    special_chars_sugar = color_for_special("\\o")
    special_chars_sugar = "".join(sorted(other_chars))

    lower_case_letters_sugar = color_for_special("\\l")
    upper_case_letters_sugar = color_for_special("\\L")
    lower_case_letters_sugar = color_for_special("a-z")
    upper_case_letters_sugar = color_for_special("A-Z")
    digits_sugar = color_for_special("0-9")

    sugars = []

    for i, (template_chars, sugar) in enumerate(
        zip(
            template_chars_list,
            [
                lower_case_letters_sugar,
                upper_case_letters_sugar,
                digits_sugar,
                special_chars_sugar,
            ],
        )
    ):
        chars_notin_template = [
            c for c in template_chars if c not in chars]
        chars_in_template = [
            c for c in template_chars if c not in chars_notin_template]

        if len(chars_in_template) == len(template_chars):
            sugars.append(sugar)
        elif len(chars_notin_template) == len(template_chars):
            continue
        elif i == 3:
            if len(chars_in_template) == 1:
                format = "{}"
            else:
                format = "[{}]"

            sugars.append(
                format.format(
                    "".join(sorted([red(c) for c in chars_in_template])))
            )
        elif len(chars_in_template) <= len(chars_notin_template):
            sugars.append("".join(sorted([red(c) for c in chars_in_template])))

        else:
            sugars.append(
                "[^{}]".format(
                    "".join(sorted([red(c) for c in chars_notin_template]))
                )
            )

    if all(
        sugar in sugars
        for sugar in [lower_case_letters_sugar, upper_case_letters_sugar, digits_sugar]
    ):
        for sugar in set(
            [lower_case_letters_sugar, upper_case_letters_sugar, digits_sugar]
        ):
            sugars.remove(sugar)
        sugars.append("\\w")

    sugar_str = "".join(sugars)

    if len(sugars) == 1:
        return [sugar_str]

    return ["[{}]".format(sugar_str)]


def group_chars_pyre(all_chars: set[str], chars: set[str]) -> list[str]:
    """ Group chars for Python's re lib. """

    assert chars, "Empty char set."
    assert "" not in chars, "ε cannot be transition symbol."
    assert all(
        len(c) == 1 for c in all_chars
    ), "`all_chars` should only contain characters."
    assert all(
        len(c) == 1 for c in chars), "`chars` should only contain characters."

    if len(chars) == len(all_chars):
        return ["."]

    return ["[{}]".format(re.escape("".join(sorted(chars))))]


def pp_re(r: StarRE, all_chars: list[str]) -> str:
    """ Pretty print V-Star's regular expression. """

    match r:
        case None:
            raise ValueError("None")
        case tuple():
            return "".join(f"{pp_re(v, all_chars)}" for v in r)
        case list():
            if len(r) == 1:
                return pp_re(r[0], all_chars=all_chars)

            chars = [c for c in r if isinstance(c, str) and len(c) == 1]

            repr_both = []

            if chars:
                repr_chars = group_chars(all_chars, chars)
                assert len(repr_chars) == 1
                repr_both.append(f"[{repr_chars[0]}]")

            others = [c for c in r if not (isinstance(c, str) and len(c) == 1)]

            if others:
                repr_both += [f"{pp_re(v, all_chars)}" for v in others]

            if len(repr_both) == 0:
                raise ValueError
            if len(repr_both) == 1:
                return repr_both[0]

            return "({})".format((" | ").join(repr_both))
        case str():
            return pp(r)
        case Star():
            return f"({pp_re(r.q, all_chars)})*"
        case Plus():
            return f"({pp_re(r.q, all_chars)})⁺"
        case Opt():
            return f"({pp_re(r.q, all_chars)})?"
        case _:
            raise ValueError(type(r))


def expand_alternation(r: StarRE) -> list:
    """ 
    Expand alternations in alternations so that they are less nested. 
    """

    match r:
        case None:
            raise ValueError("None")
        case tuple():
            alts = [tuple()]
            for subr in r:
                alts = [
                    alt + (sub_alt,)
                    for sub_alt in expand_alternation(subr)
                    for alt in alts
                ]

            return alts
        case list():
            if '1' in r:
                return [r]
            alts = [expand_alternation(alt) for alt in r]
            # merge_alt(alts)
            return alts
        case str():
            return [r]
        case Star():
            return [r]
        case Plus():
            return [r]
        case Opt():
            return [r]
        case _:
            raise ValueError(type(r))


def list_alts(r: StarRE) -> dict:
    """ List levaes in alternatives. """

    leaves = {}

    match r:
        case None:
            raise ValueError("None")
        case tuple():
            for subr in r:
                leaves.update(list_alts(subr))
        case list():

            if all(isinstance(c, str) and len(c) == 1 for c in r):
                return {}

            new_leaves = {}
            for subr in r:
                new_leaves.update(list_alts(subr))

            new_leaves.update({re2pyre(subr): subr for subr in r})

            return new_leaves
        case str():
            pass
        case Star(q=q):
            leaves.update(list_alts(q))
        case Plus(q=q):
            leaves.update(list_alts(q))
        case Opt(q=q):
            leaves.update(list_alts(q))
        case _:
            raise ValueError(type(r))

    return leaves


def list_str_literal(r: StarRE) -> dict[str, tuple]:
    """ List str levaes in alternatives. """

    leaves = {}

    match r:
        case None:
            raise ValueError("None")
        case tuple():
            # print_info(f"tuple: {r}")
            str_seq = tuple()
            for subr in r:
                if isinstance(subr, str):
                    str_seq += (subr,)
                else:
                    if len(str_seq) > 0 and any(len(c) > 1 for c in str_seq):
                        leaves[re2pyre(str_seq)] = str_seq
                        str_seq = tuple()

                    leaves.update(list_str_literal(subr))

            if len(str_seq) > 0:
                leaves[re2pyre(str_seq)] = str_seq
                str_seq = tuple()

        case list():
            if all(isinstance(c, str) and len(c) == 1 for c in r):
                return {}
            for subr in r:
                leaves.update(list_str_literal(subr))
        case str():
            leaves[re2pyre(r)] = (r,)
        case Star(q=q):
            leaves.update(list_str_literal(q))
        case Plus(q=q):
            leaves.update(list_str_literal(q))
        case Opt(q=q):
            leaves.update(list_str_literal(q))
        case _:
            raise ValueError(type(r))

    return leaves


def re2pyre(r: StarRE) -> str:
    """ Convert V-Star's RE to Python's RE. """

    match r:
        case None:
            raise ValueError("None")
        case tuple():
            return "({})".format("".join(f"{re2pyre(v)}" for v in r))
        case list():
            return "(" + "|".join(f"{re2pyre(v)}" for v in r) + ")"
        case str():
            return re.escape(r)
        case Star():
            return f"({re2pyre(r.q)})*"
        case Plus():
            return f"({re2pyre(r.q)})+"
        case Opt():
            return f"({re2pyre(r.q)})?"
        case _:
            raise ValueError(type(r))
