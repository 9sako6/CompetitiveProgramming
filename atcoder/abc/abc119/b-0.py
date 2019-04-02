N = int(input())

summon = 0
for i in range(N):
    x, u = input().split()
    x = float(x)
    if u == 'JPY':
        summon += x
    else:
        summon += x*380000

print(summon)
