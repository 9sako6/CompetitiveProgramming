n=int(input())
s=input()
ans = 0
for i in range(1, n):
    a=set(s[:i+1])
    b=set(s[i:])
    ans = max(ans, len(a&b))
print(ans)