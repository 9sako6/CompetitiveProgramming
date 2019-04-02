import math
N, M = map(int, input().split())

ans = 1
for a in range(1, int(math.sqrt(M))):
    b = int(M / a)
    if M%a != 0:
        continue
    if a * N <= M:
        ans = max(ans, a)
    if b * N <= M:
        ans = max(ans, b)

print(ans)

