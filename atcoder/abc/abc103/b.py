s = list(input())
t = list(input())
ans = 'No'
if s == t:
    ans = 'Yes'

cnt = 0
while s != t:
    cnt += 1
    s = [s[-1]] + s[:-1]
    if s == t:
        ans = 'Yes'
    
    if cnt > len(s):
        break

print(ans)
