N, Q = map(int, input().split())
S = input()
memo = [0]*(N+1)
for i in range(N-1):
    if S[i] == 'A' and S[i+1] == 'C':
        memo[i+1] = memo[i]+1
    else:
        memo[i+1] = memo[i]
ans = []
for _ in range(Q):
    l, r = map(int, input().split())
    ans.append(memo[r-1]-memo[l-1])

print('\n'.join(map(str, ans)))