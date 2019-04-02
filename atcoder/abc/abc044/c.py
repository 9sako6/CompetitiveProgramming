N,A=map(int, input().split())
x=list(map(int, input().split()))
dp = [[[0]*(51*51) for _ in range(N+1)] for _ in range(N+1)]
# dp[j][k][s]
for j in range(N+1):
    for k in range(j+1):
        for s in range(51*51):
            if j==0 and k==0 and s==0:
                dp[j][k][s] = 1
            elif j >=1 and s < x[j-1]:
                dp[j][k][s] = dp[j-1][k][s]
            elif j >=1 and k >= 1 and s >= x[j-1]:
                dp[j][k][s] = dp[j-1][k][s]+dp[j-1][k-1][s-x[j-1]]
            else:
                dp[j][k][s] = 0

ans = 0
for i in range(1, N+1):
    ans+= dp[N][i][i*A]
print(ans)