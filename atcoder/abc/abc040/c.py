N=int(input())
a=list(map(int, input().split())) + [10**6]*10
dp = [10**6]*(10**6)
dp[0]=0
for i in range(N):
    dp[i+1] = min(dp[i] + abs(a[i]-a[i+1]), dp[i+1])
    dp[i+2] = min(dp[i] + abs(a[i]-a[i+2]), dp[i+2])
print(dp[N-1])