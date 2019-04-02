I = lambda: list(map(int, input().split()))

N, T = I()
ct = [I() for _ in range(N)]

minc = 9999

for i in range(N):
    if T >= ct[i][1] and minc >= ct[i][0]:
        minc = ct[i][0]

print(minc if minc != 9999 else 'TLE')
