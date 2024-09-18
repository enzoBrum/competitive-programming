from itertools import chain, combinations
from sys import argv

l = list(range(int(argv[1])))
cnt = [0 for _ in range(len(l))]

for c in chain.from_iterable(combinations(l, r) for r in range(len(l) + 1)):
    for j in c:
        cnt[j] += 1
        
print(cnt)