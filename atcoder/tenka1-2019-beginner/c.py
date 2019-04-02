N=int(input())
S = input()
w = [0]*(N+1)
b = [0]*(N+1)
for i, s in enumerate(S):
    if s=='.':
        w[i+1] = w[i]+1
        b[i+1] = b[i]
    elif s=='#':
        b[i+1] = b[i]+1
        w[i+1] = w[i]
ans = 10**20
for i in range(N+1):
    ans = min(ans, b[i]+w[N]-w[i])
print(ans)