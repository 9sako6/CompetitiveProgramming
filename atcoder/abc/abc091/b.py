N = int(input())
s = [input() for _ in range(N)]
M = int(input())
t = [input() for _ in range(M)]

maxs = 0

for si in s:
    tmp = s.count(si) - t.count(si)
    if tmp > maxs:
        maxs = tmp

print(maxs)
