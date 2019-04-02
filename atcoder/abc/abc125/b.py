n=int(input())
v=list(map(int, input().split()))
c=list(map(int, input().split()))

xmy = 0
dp=[0]*n
dp[0] = max(v[0]-c[0], 0)
for i in range(1, n):
    dp[i] = max(dp[i-1]+v[i]-c[i], dp[i-1])
print(dp[-1])