n = int(input())
if n == 1:
    print(1)
    exit()

i = 2
L = [0]*(n+1)
L[0] = 2
L[1] = 1
while i != n:
    L[i] = L[i-1]+L[i-2]
    i+=1

print(L[n-1]+L[n-2])
