n, m = list(map(int, input().split()))
s = input()
t = input()

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

l = int(n*m / gcd(n, m))

if len(s) < len(t):
    tmp = s
    s = t
    t = tmp


for i in range(0, min(n, m)):
    if s[i+max(n, m)//min(n, m)]:

        if s[i+max(n, m)//min(n, m)] != t[i]:
            print(-1)
            exit()

