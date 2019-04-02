n=int(input())
ans = 0
a = 0
b = 0
ba = 0
for i in range(n):
    s = input()
    ans += s.count('AB')
    s0 = s[0]
    s1 = s[-1]
    b += 1 if s0 == 'B' else 0
    a += 1 if s1 == 'A' else 0
    ba += 1 if s0 == 'B' and s1 == 'A' else 0

print(ans + min(a,b)-1 if (ba > 0 and ba == a and ba == b) else ans + min(a,b))
