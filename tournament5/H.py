line = input()
ans = cur = 0
ans_i = 0

for i, j in enumerate(line):
    if j == '+':
        cur += 1
    else:
        cur -=1

    if cur > ans:
        ans = max(ans, cur)
        ans_i = i
print(ans_i+1)
