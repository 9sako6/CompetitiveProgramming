n=int(input())
a=list(map(int, input().split()))
ans = 0
m = 1
for ai in a:
    m *= ai
m -= 1
for ai in a:
    ans += m%ai
print(ans)