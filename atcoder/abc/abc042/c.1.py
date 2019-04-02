N,K=map(int, input().split())
D=list(map(int, input().split()))
use=[]
for i in range(10):
    if i not in D:
        use.append(i)
ans = ''

for n in list(map(int, list(str(N)))):
    if n > use[-1]:
        ans+=str(use[0])
    else:
        for i in use:
            if i >= n:
                ans+=str(i)
                break

if str(N)[0] < ans[0]:
    ans = ans[0]+str(use[0])*(len(ans)-1)

if N-int(ans) > 0:
    ans = str(use[0]) + str(use[0])*len(str(N)) if use[0]!=0 else str(use[1])+str(use[0])*len(str(N))



print(ans)

