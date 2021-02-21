import os

r, w = os.pipe()
pid = os.fork()

if pid == 0:
    # child
    os.close(r)
    wd = os.fdopen(w, "w")
    wd.write("Hello World")
    # What Happened?
    wd.close() # EOF! All Closed!
else:
    # parent
    os.close(w)
    rd = os.fdopen(r, "r")
    text = rd.read(16)
    print(f"I'm parent!: read from child: {text}")
    rd.close()
