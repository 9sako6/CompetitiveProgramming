from fractions import gcd
a, b, c, d = map(int, input().split())
n = b-a+1
cd = int(c*d/gcd(c, d))
cdiv = int(b/c)-int((a-1)/c)
ddiv = int(b/d)-int((a-1)/d)
cddiv = int(b/cd)-int((a-1)/cd)
print(n-cdiv-ddiv+cddiv)
