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

ruiwa = [0]*(len(memo)+1)
for i in range(len(memo)):
    ruiwa[i+1]=ruiwa[i]+memo[i]

for i in range(N)[::2]:
    if i < N:
        tmp = ruiwa[min(i+add, len(ruiwa)-1)] - ruiwa[min(i, len(ruiwa)-1)]
        ans = max(ans, tmp)
print(ans)
