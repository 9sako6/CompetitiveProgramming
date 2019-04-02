N,K = map(int, input().split())
S = input()
memo =[]
now = '1'
cnt = 0
for s in S:
    if s==now:
        cnt+=1
    else:
        memo.append(cnt)
        cnt=1
        now = '1' if now=='0' else '0'
else:
    memo.append(cnt)
if S[-1] == '0':
    memo.append(0)
ans = 0
add = K*2+1
for i in range(N)[::2]:
    if i < N:
        ans = max(ans, sum(memo[i:i+K*2+1]))
print(ans)
