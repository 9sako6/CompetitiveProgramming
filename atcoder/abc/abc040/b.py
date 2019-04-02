n = int(input())
memo = []
for i in range(1, int(n**0.5 + 1)):
    memo.append(abs(i-(n//i))+(n-(i*(n//i))))
print(min(memo))
