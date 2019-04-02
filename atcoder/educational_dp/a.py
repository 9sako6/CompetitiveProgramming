n=int(input())
h=list(map(int, input().split()))+[0]*10
dp=[10**10]*(n+10)
dp[0]=0
dp[1]=abs(h[0]-h[1])
for i in range(0, n):
    dp[i+1] = min(dp[i+1], dp[i]+abs(h[i]-h[i+1]))
    dp[i+2] = min(dp[i+2], dp[i]+abs(h[i]-h[i+2]))
print(dp[n-1])
