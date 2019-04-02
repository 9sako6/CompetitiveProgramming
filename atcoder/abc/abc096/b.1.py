abc = list(map(int, input().split()))
k = int(input())
abc.sort()
abc[-1] *= 2**k
print(sum(abc))
