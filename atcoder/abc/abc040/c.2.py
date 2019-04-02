N=int(input())
a=list(map(int, input().split()))
dp = [10**10]*(N)
dp[0]=0
dp[1] = abs(a[0]-a[1])
for i in range(2, N):
    cos1 = abs(a[i]-a[i-1])+dp[i-1]
    cos2 = abs(a[i]-a[i-2])+dp[i-2]
    dp[i] = min(cos1, cos2)
print(dp[-1])
print(dp)