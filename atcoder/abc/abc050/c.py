N = int(input())
A = list(map(int, input().split()))
from collections import Counter
MOD = 10**9+7
def is_ok(n, a_list):
    if N%2==0:
        # even
        c = Counter(a_list)
        for a in a_list:
            if a%2==0:
                return False
            elif c[a] != 2:
                return False
    else:
        # odd
        c = Counter(a_list)
        for a in a_list:
            if a%2==1:
                return False
            elif a == 0:
                if c[a]!=1:
                    return False
            elif c[a] != 2:
                return False
    
    return True


if (is_ok(N, A)):
    print((2**(N//2))%MOD if N%2==0 else (2**((N-1)//2))%MOD)
else:
    print(0)