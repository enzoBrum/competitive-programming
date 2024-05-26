from datetime import datetime, timedelta
from math import ceil


v, e = [int(x) for x in input().split()]

v = 60*v*60
v = v/e

t = datetime(year=1, month=1 , day=1, hour=19, minute=0, second=0)




curr_s = 19*3600



final_s = v
final_s %= (3600*24)



d = datetime(year=1, month=1, day=1, hour=19, minute=0, second=0)
t += timedelta(seconds=final_s)

h = t.hour

if h < 10:
    h = f"0{h}"
else:
    h = str(h)

m = t.minute

if m < 10:
    m = f"0{m}"
else:
    m = str(m)

print(f"{h}:{m}")

