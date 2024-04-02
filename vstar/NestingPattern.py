import os
import pickle
from vstar.Oracle import Oracle
from .Colors import blue
from .Utils import info, path_to_result
from .Utils import pp

# NOTE - A nesting pattern is (s,u,x,v,y,z), where s=u+x+v+y+z.
NestPattern = tuple[str, str, str, str, str, str]
# NOTE - (s,(i,j),(k,l)): call=s[i:j],ret=s[k,l]
IntNestPattern = tuple[str, tuple[tuple[int, int], tuple[int, int]]]

IntervalList = list[tuple[int, int]]
# NOTE - {s: ([(i,j),...],[(k,l),...])}: call = s[i:j], ret = s[k:l]
IntervalDict = dict[str, tuple[IntervalList, IntervalList]]


def pp_pattern(pattern: NestPattern | IntNestPattern) -> str:
    """ Pretty print a nesting pattern. """

    match pattern:
        case (s, u, x, z, y, v):
            return f"{u} {pp(x)} {z} {pp(y)} {v}"
        case s, ((i, j), (k, l)):
            s, u, x, z, y, v = indices2pattern(s, i, j, k, l)
            return f"{u} {pp(x)} {z} {pp(y)} {v}"
        case _:
            raise ValueError(pattern)


def enum_xy(n: int):
    """
    Enumerate all (i,j), (k,l), where 0 ≤ i < j ≤ k < l ≤ n.
    Order: outermost to innermost; incresing length.
    """

    for i in range(0, n - 1):
        for j in range(n, 1, -1):
            for k in range(i + 1, j):
                for l in range(k, j):
                    yield ((i, k), (l, j))


def overlap(i, j, a, b):
    """ (i < a < j < b) or (a < i < b < j) """
    return (i < a < j < b) or (a < i < b < j)


def include(i, j, a, b):
    """ i <= a < b <= j or i <= a < b <= j """
    return i <= a < b <= j


def cross(i, j, a, b):
    return (i < a < j < b) or (a < i < b < j)


def indices2pattern(s, i1, j1, i2, j2) -> NestPattern:
    u = s[:i1]
    x = s[i1:j1]
    z = s[j1:i2]
    y = s[i2:j2]
    v = s[j2:]
    return (s, u, x, z, y, v)


def refine_patterns(intervalDict: IntervalDict) -> None:
    """
    Refine patterns (x,y) in intervalDict to candidate token strings.
    """

    for s in intervalDict:
        interval_call2 = []
        interval_retn2 = []

        for (i1, j1), (i2, j2) in zip(*intervalDict[s]):

            merged_xy = None
            for index, ((i3, j3), (i4, j4)) in enumerate(
                    zip(interval_call2, interval_retn2)):

                if include(i1, j1, i3, j3) and include(i4, j4, i2, j2):
                    merged_xy = (index, (i3, j3), (i2, j2))
                    break
                elif include(i3, j3, i1, j1) and include(i2, j2, i4, j4):
                    merged_xy = (index, (i1, j1), (i4, j4))
                    break

            if merged_xy:
                index, (i, j), (r, l) = merged_xy
                interval_call2[index] = ((i, j))
                interval_retn2[index] = ((r, l))

                merged_nesting_pattern = indices2pattern(s, i, j, r, l)

                nesting_pattern = indices2pattern(s, i1, j1, i2, j2)
                info(blue("Merge ") + pp_pattern(nesting_pattern) +
                     blue(' and ') +
                     pp_pattern(indices2pattern(s, i3, j3, i4, j4)) +
                     blue(' to ') + pp_pattern(merged_nesting_pattern))

                continue

            interval_call2.append((i1, j1))
            interval_retn2.append((i2, j2))

        intervalDict[s] = (interval_call2, interval_retn2)


def find_pattern(oracle, s: str) -> tuple[IntervalList, IntervalList]:
    """
    Find nesting patterns in string s.

    Properties of the returned patterns:
    Patterns in the same string
    1. do not cross
    2. do not overlap
    """

    k = 2
    interval_call = []
    interval_retn = []

    for (i1, j1), (i2, j2) in enum_xy(len(s)):
        # NOTE - Nesting pattern
        _, u, x, z, y, v = indices2pattern(s, i1, j1, i2, j2)

        # NOTE - Patterns should not nest.
        if any(include(i1, j1, i3, j3) and include(i2, j2, i4, j4)
                for (i3, j3), (i4, j4) in zip(interval_call, interval_retn)):
            continue

        # NOTE - Call/return token should not start with r*.
        def k_pre_sufix(s, u, v):
            for i in range(1, len(s)):
                if oracle(u + s[:i] * k + s[i:] + v) or oracle(u + s[:i] + s[i:] * k + v):
                    return True

            return False

        if (k_pre_sufix(x, u, z + y + v) or k_pre_sufix(y, u + x + z, v)):
            continue

        must_be_valid = [u + x * k + z + y * k + v]
        must_be_invalid = [u + x * k + z + y + v,
                           u + x + z + y * k + v]

        if any(not oracle(ts) for ts in must_be_valid):
            continue

        if any(oracle(ts) for ts in must_be_invalid):
            continue

        # NOTE - remove shifts of patterns
        if any(cross(i1, j1, i3, j3) or cross(i2, j2, i4, j4)
               for (i3, j3), (i4, j4) in zip(interval_call, interval_retn)):
            continue

        nesting_pattern = (s, u, x, z, y, v)
        info(pp_pattern(nesting_pattern))

        interval_call.append((i1, j1))
        interval_retn.append((i2, j2))

    return interval_call, interval_retn


def find_all_pattern(
        oracle: Oracle,
        seed_strings: list[str],
        renew_pattern=False) -> IntervalDict:
    """Find all nesting patterns within each seed string.

    Return: An IntervalDict `{s: ([(i,j), ...], [(k,l), ...]), ...}`, where the key `s` is a seed string, the value contains two lists. The first list contains the indices of `x`, and the second list contains the indices of `y`. 
    Nesting pattern `(x, y)` in `s` is `(s[i:j], s[k:l])`.
    """

    interval_dict: IntervalDict = {}
    pattern_folder = os.path.join(path_to_result, 'nesting_pattern')
    pattern_file = os.path.join(pattern_folder,
                                f"{oracle.name}.nesting_pattern.pickle")

    if not renew_pattern and os.path.exists(pattern_file):
        with open(pattern_file, 'rb') as handle:
            interval_dict = pickle.load(handle)

        for s, intervals in interval_dict.items():
            for interval in zip(*intervals):

                info(f"Cached: {pp_pattern((s, interval))}")
    else:
        if not os.path.exists(pattern_folder):
            os.mkdir(pattern_folder)

        for i, s in enumerate(seed_strings[:]):
            patterns = find_pattern(oracle, s)

            if patterns[0]:
                interval_dict[s] = patterns

        with open(pattern_file, 'wb') as f:
            pickle.dump(interval_dict, f)

    return interval_dict
