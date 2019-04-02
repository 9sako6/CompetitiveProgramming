memo = []

a,b,k = map(int, input().split())
for i in range(1,1000):
    if a % i == 0 and b % i == 0:
        memo.append(i)
memo.sort(reverse=True)
print(memo[k-1])
