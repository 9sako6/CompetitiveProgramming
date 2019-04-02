n,x=map(int, input().split())
m = [int(input()) for _ in range(n)]
ans = n
m.sort()
x -=sum(m)
while x > 0:
    x -= m[0]
    if x >= 0:
        ans += 1
print(ans)