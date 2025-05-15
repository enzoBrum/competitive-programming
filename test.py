from pathlib import Path
import subprocess

d = list(Path("./contest-packages/input").iterdir())

for in_file in sorted(d):
    print(f"Trying {in_file}")
    out_file = Path(f"./contest-packages/output/{in_file.name}")

    result = (
        subprocess.run(f"./main < {in_file}", shell=True, stdout=subprocess.PIPE)
        .stdout.decode()
        .strip()
    )

    if result == out_file.read_text().strip():
        print("PASSED")
    else:
        print("FAILED")
        input()
