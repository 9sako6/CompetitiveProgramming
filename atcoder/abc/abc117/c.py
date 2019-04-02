N, M = map(int, input().split())
x = list(map(int, input().split()))

if N>=M:
    print(0)
    exit()

x.sort()
kyori = [0]*(M-1)
for i in range(M-1):
    kyori[i] = (x[i+1] - x[i], i)
kyori.sort(key=lambda k: k[0], reverse=True)
kyori = kyori[:N-1]
kyori.sort(key=lambda k: k[1])
cost = 0
now = 0
for i in range(len(kyori)):
    t = kyori[i][1]
    if now < M:
        cost += x[t]-x[now]
    now += t+1
if now < M:
    cost += x[-1] - x[now]
print(cost)

