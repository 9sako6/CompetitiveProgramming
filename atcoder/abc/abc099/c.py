N=int(input())
dp=[i for i in range(N+1)]

for i in range(1, N+1):
    n = 1
    while n <= i:
        dp[i] = min(dp[i], dp[i-n]+1)
        n*=6
    n = 1
    while n <= i:
        dp[i] = min(dp[i], dp[i-n]+1)
        n*=9

print(dp[N])