def gen_all(num: str) -> list[int]:
    n = len(num)
    ret = [0]

    for i, c in enumerate(num):
        if c == "0":
            continue
        if c == "1":
            for j in range(len(ret)):
                ret[j] |= 1 << (n - i - 1)
        else:
            limit = len(ret)
            for j in range(limit):
                ret.append(ret[j] | (1 << (n - i - 1)))
    return ret


def main():
    m = input()
    n = input()

    all_m = gen_all(m)
    all_n = gen_all(n)

    for cur_m in all_m:
        for cur_n in all_n:
            if cur_m % cur_n == 0:
                ans = ""
                nn = len(m)
                for i, c in enumerate(m):
                    if c != "*":
                        ans += c
                    else:
                        num = (1 << (nn - i - 1)) & cur_m
                        ans += "1" if num > 0 else "0"
                print(ans)
                return


if __name__ == "__main__":
    main()
