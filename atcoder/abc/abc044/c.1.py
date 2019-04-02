N, A = map(int, input().split())
x = list(map(int, input().split()))
X = max(x+[A])

# dp[j][k][s]
# x...xjからk枚選んで合計がs
dp = [[[0]*51]*51]*(51*51)

dp[0][0][0]=1

for j in range(1, N+1):
    for k in range(N+1):
        for s in range(X*N+1):
            if x[j] > s:
                dp[j][k][s] = dp[j-1][k][s]
            elif j>=1 and x[j] <= s:
                dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j]]


for i in range(1, N+1):
    ans += dp[N][i][i*A]
print(ans)
