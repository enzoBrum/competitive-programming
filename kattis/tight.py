from sys import stdin


lines = stdin.readlines()

for line in lines:
    k, n = [int(x) for x in input().split()]
    
    dp = [0 for _ in range(n+1)]
    
    total = (k+1 ** n)