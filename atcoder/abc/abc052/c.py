def is_prime(n):
    if n == 2:
        return True
    else:
        for i in range(2, int((n**(1/2)))+1):
            if n % i == 0:
                return False
        return n > 1

from collections import Counter
N = int(input())
MOD = 10**9+7

primes = [i for i in range(N+1) if is_prime(i)] # N以下の素数

c = Counter(primes) # 各素数で何回割れるかを記録する
                    # 最後に約数の個数を求める時、
                    # (各素因数の指数+1)を掛け合わせるので1で初期化されるCounterは都合が良い

# N以下の数について、各素数で割れた回数を数えていく
for j in range(2, N+1):
    for prime in primes:
        while j % prime == 0:
            j //= prime
            c[prime] += 1

ans = 1
for cnt in c.values():
    ans *= cnt # 初期値が1なので1を足す必要はない
print(ans%MOD) # 剰余で答えるのを忘れずに