N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(N)]
ab = sorted(ab, key=lambda x: x[0])

price = 0
cnt = 0
for info in ab:
    a, b = info
    if cnt + b >= M:
        price += (M-cnt)*a
        break
    else:
        cnt += b
        price += a*b

print(price)
