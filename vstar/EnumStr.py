def subStr(s, min_len=1):
    """
    Return (i,j), where s[i:j] traverses all substrings of length l of s.
    """
    for i in range(len(s)-min_len+1):
        for j in range(i+min_len, len(s)+1):
            yield s[i:j]


def subStrInd(n, l):
    """
    Return (i,j), where s[i:j] traverses all substrings of length l of s.
    """
    for i in range(n-l+1):
        yield (i, i+l)

def allsubs_maxmin(s, minlen=2):
    for l in range(len(s), minlen-1, -1):
        for i, j in subStrInd(len(s), l):
            yield i, j

