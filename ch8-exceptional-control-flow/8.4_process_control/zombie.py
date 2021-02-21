import os
import sys
import time

stat = os.fork()
print(stat)
if stat == 0:
    sys.exit()
time.sleep(12000)
os.wait()
