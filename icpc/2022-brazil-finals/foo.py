from pathlib import Path
import subprocess

inputs = Path("./contest_packages/C/input")
outputs = Path("./contest_packages/C/output")

inputs = sorted(list(inputs.iterdir()))
outputs = sorted(list(outputs.iterdir()))

for i , test in enumerate(inputs):
    result = subprocess.run(f"./main < {test}", stdout=subprocess.PIPE, shell=True).stdout.decode().strip()
    expected = outputs[i].read_text().strip()

    if result == expected:
        print(f"{i} --> OK")
    else:
        print(f"{i} --> NOT OK\nGOT: {result}\nEXPECTED: {expected}")
        input()
