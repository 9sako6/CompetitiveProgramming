N,T=map(int, input().split())
t=list(map(int, input().split()))
ans=T
for i in range(1, N):
    x = (t[i]-t[i-1]) - T
    if x > 0:
        ans += T
    else:
        ans += T+x
print(ans)