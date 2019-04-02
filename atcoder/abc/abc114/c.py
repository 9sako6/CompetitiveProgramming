N = int(input())
dp = []

def dfs(x):
    if len(set(str(x))) == 3:
        dp.append(x)

    if x < 10**9:
        dfs(x*10+3)
        dfs(x*10+5)
        dfs(x*10+7)

dfs(0)
print(len([item for item in dp if item <= N]))
