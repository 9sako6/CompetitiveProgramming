N = int(input())

def f(a, b):
    a, b = str(a), str(b)
    return len(a) if len(a) > len(b) else len(b)

def isPrime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    else:
        for i in range(2, int(n**(1/2))+1):
            if n%i == 0:
                return False
        return True

if isPrime(N):
    print(f(N, 1))
else:
    ans = 10**20
    for i in range(1, int(N**(1/2))+1)[::-1]:
        if N%i == 0:
            ans = min(ans, f(N//i, i))
    print(ans)