xa = []
y = int(input())
for x in range(0, y):
    element = int(input())
    xa.append(element)
z = set()
result = []
for x in xa:
    if x not in z:
        result.append(x)
        z.update(xa)
print(z)
