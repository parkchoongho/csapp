import signal
import time
import sys

def signal_handler(sig, frame):
    print('You sent me SIGSTOP! let me kill~')
    sys.exit(0)

signal.signal(signal.SIGALRM, signal_handler)


s = 0
for n in range(100000000000000000):
    print(1)
    time.sleep(1)
