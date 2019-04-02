n, x = map(int, input().split())
M = []
for _ in range(n):
    M.append(int(input()))

M.sort()
cnt = 0
for m in M:
  x -= m
  cnt += 1

while x > 0:
    x -= M[0]
    if x >= 0:
        cnt += 1


print(cnt)
