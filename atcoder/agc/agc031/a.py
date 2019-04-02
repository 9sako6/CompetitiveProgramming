n = int(input())
s = input()
dp = [-1]*n
dp[0] = 1

def calcNext(string):
    res = [[0]*(len(string)+1) for _ in range(27)]
    for i in range(26)[::-1]:
        for j in range(26):
            print(i, j)
            res[i][j] = res[i+1][j]
            res[i][int(string[i]-'a')] = i

    return res

print(calcNext(s))

# print(ans % (10**9 + 7))
