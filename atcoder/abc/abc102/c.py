N=int(input())
A=list(map(int, input().split()))

x = [A[i-1]-i for i in range(1, N+1)]
x.sort()

mid = x[len(x)//2]
ans = 0
for i in range(1, N+1):
    ans += abs(A[i-1]-(mid+i))
print(ans)