S=input()
ans=0
cnt=0
for i, s in enumerate(S):
    if s=='W':
        cnt+=1
        ans+=i-cnt+1

print(ans)