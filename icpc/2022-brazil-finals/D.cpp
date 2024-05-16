n, h, w = [int(x) for x in input().split()]

for i in range(n):
    fst, snd = input().split()

    ans = ""

    if fst == "Y":
        ans += "Y"
        h -= 1
        w += 1
    elif w == 0:
        ans += "Y"
        h -= 1
        w += 1
    else:
        ans += "N"

    if snd == "Y" or h == 0:
        w -= 1
        h += 1
        ans += " Y"
    else:
        ans += " N"

    print(ans)


