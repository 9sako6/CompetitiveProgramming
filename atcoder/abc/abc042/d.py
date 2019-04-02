H, W, A, B = map(int, input().split())

import math

def con(a, b):
    return math.factorial(a+b)//(math.factorial(a)*math.factorial(b))

MOD = 10**9+7

sowa = con(H, W) % MOD
for i in range(min(A, B)+1):
    sowa -= (con(H-i, i)%MOD)*(con(W-i, i)%MOD)

print(sowa)