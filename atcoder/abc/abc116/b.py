s = int(input())
memo = [0]*1000000
memo[0] = s
dic = {s:1}

def f(n):
    return int(n/2) if n%2==0 else 3*n+1

for i in range(1, 1000002):
    memo[i] = f(memo[i-1])
    if dic.get(memo[i]):
        print(i+1)
        exit()
    else:
        dic[memo[i]] = 1