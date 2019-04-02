n = int(input())
s = int(input())

memo = [[False for _ in range(n)] for _ in range(n)]

def f(x,y):
    print(memo[x][y])
    if memo[x][y]:
        return memo[x][y]
    elif y < x:
        memo[x][y] = y
        return y
    else:
        memo[x][y] = f(x, y//x)+(y%x)
        return memo[x][y]

# f()
for i in reversed(range(n)):
    print(f(i, n))
    if f(i, n) == s:
        print(b)
        exit()

print(-1)
