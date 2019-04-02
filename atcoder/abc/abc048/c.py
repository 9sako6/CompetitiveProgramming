N, x = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
if a[0] > x:
    ans += a[0]-x
    a[0] = x
for i in range(N-1):
    ac = a[i]+a[i+1]
    if ac > x:
        ans += ac-x
        a[i+1] -= ac-x
print(ans)