n = input()

_, n = [int(x) for x in input().split()]

from math import gcd

for i in range(n - 1):
    _, n2 = [int(x) for x in input().split()]
    n = gcd(n, n2)
print(n)
