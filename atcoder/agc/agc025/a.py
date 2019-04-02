N = int(input())

if N%10 == 0:
    print(10)
else:
    sumN = map(int, list(str(N)))
    print(sum(sumN))
