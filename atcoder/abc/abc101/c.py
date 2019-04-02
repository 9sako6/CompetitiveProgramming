n,k=map(int, input().split())
a=list(map(int, input().split()))
ans = 0
if n <= k:
    print(1)
    exit()
cnt = k
while cnt < n:
    cnt += k-1
    ans += 1

print(ans+1)