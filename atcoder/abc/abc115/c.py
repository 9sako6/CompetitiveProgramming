N, K = list(map(int, input().split()))
h = [int(input()) for _ in range(N)]

hs = sorted(h)
ans = hs[-1] - hs[0]
for i in range(N - K + 1):
    ans = min(ans, hs[i+K-1]-hs[i])

print(ans)
