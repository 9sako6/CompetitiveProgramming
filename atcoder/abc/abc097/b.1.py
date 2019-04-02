x = int(input())
ans=0
for i in range(2, 10):
    for j in range(1, x+1):
        if j**i <= x:
            ans = max(ans, j**i)
print(ans)