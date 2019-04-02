N = int(input())

dp = []

def dfs(x):
    if check(x):
        dp.append(x)

    if (x <= 10**9):
        dfs(10*x+3)
        dfs(10*x+5)
        dfs(10*x+7)

def check(x):
    set_x = set(list(str(x)))
    if set_x >= {'3','5','7'} and set_x <= {'3','5','7'}:
        return True


dfs(0)
print(len([item for item in dp if item <= N]))

# 999, 6
# 9999, 42
# 99999, 192
# 999999, 732
# 9999999, 2538
# 99999999, 8334
# 999999999, 26484
