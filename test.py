import subprocess
from subprocess import Popen
from sys import argv

def test(num: int, target: int) -> bool:
    proc = Popen(["./main"], stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    proc.stdin.write(f"{num}\n".encode("ascii"))
    proc.stdin.flush()

    cnt = 0
    suc = True
    
    lr = []
    while True:
        if cnt > 16 and suc:
            print("CNT ERROR")
            suc = False
        line = proc.stdout.readline().decode()
        lr.append(line)
        if "L:" in line:
            continue
        cnt += 1
        if not line.strip():
            continue

        if line[0] == 'A':
            proc.terminate()
            if not suc:
                print(f"RIGHT ANS: {int(line.split()[1]) == target} --: {cnt=}")
                print("".join(lr))
            return int(line.split()[1]) == target and suc

        l1, r1, l2, r2 = [int(x) for x in line[1:].strip().split()]
        w1 = l1 <= target <= r1
        w2 = l2 <= target <= r2

        proc.stdin.write(f"{int(w1)} {int(w2)}\n".encode("ascii"))
        lr.append(f"{int(w1)} {int(w2)}\n")
        proc.stdin.flush()

if len(argv) > 1:
    print(test(int(1e9), int(argv[1])))
    exit(0)

for i in range(int(1e9), 0, -1):
    for j in range(1, i+1):
        result = test(i, j)
        if not result:
            print(f"{i} -> {j} = False")
            exit(1)
        else:
            print(f"{i} -> {j} True")
