N, T = map(int, input().split())

ct = [list(map(int, input().split())) for i in range(N)]
minnum = 9999
for c, t in ct:
    if t <= T:
        if minnum >= c:
            minnum = c

print(minnum if minnum != 9999 else 'TLE')
