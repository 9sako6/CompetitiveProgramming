def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd (a, b) * b

n = int(input())
a = list(map(int, input().split()))
l = 1
for ai in a:
    l = lcm(l, ai)

ans = 0
mod = 10**9 + 7
for ai in a:
    ans += l // ai

print(ans % mod)
