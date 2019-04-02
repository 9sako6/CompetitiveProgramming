N = int(input())
a = list(map(int, input().split()))

dp = [10**10]*N
dp[0] = 0
dp[1] = abs(a[1]-a[0])
for i in range(2, N):
    c1 = dp[i-2]+abs(a[i-2]-a[i])
    c2 = dp[i-1]+abs(a[i-1]-a[i])
    dp[i] = min(c1, c2)

print(dp[-1])
