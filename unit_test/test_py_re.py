import re

r = re.compile("a((a|c)|b)c(c|d)")

strs = ["aacc",
        "aacd",
        "abc",
        "abcd",]

for s in strs:
    print(r.match(s))
