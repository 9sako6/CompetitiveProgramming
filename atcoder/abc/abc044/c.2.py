n, a = map(int, input().split())
x = list(map(int, input().split()))
# i番目まででj枚選んだ時合計がk
# dp[i][j][k]
dp = [[[0]*(51*2) for _ in range(51*2)] for _ in range(51*51)]
for i in range(n+1):
    for j in range(n+1):
        for k in range(a+1):
            if i == 0 and j == 0 and k == 0:
                dp[i][j][k] = 1
            else:
                dp[i][j][k] += dp[i-1][j][k]
                if k >= x[i-1]:
                    dp[i][j][k] += dp[i-1][j-1][k-x[i-1]]
            print(i, j, k, dp[i][j][k])
ans = 0
for j in range(n+1):
    ans += dp[n][j][j*a]

print(ans)