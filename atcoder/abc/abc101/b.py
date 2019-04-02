n = list(input())
N = int(''.join(n))

s = 0
for i in n:
    s += int(i)

print('Yes' if N%s==0 else 'No')
