n, p = [int(x) for x in input().split()]
v = [int(x) for x in input().split()]

ans = -1
for n in v:
    if n <= p and n > ans:
        ans = n
print(ans)
