import time

start = time.time()
total, s = 100000, 0
a = [True] * total
a[0] = a[1] = False
for i, isprime in enumerate(a):
    if isprime:
        s += 1
        for n in range(i * i, total, i):
            a[n] = False
print(time.time() - start)
print(s)
