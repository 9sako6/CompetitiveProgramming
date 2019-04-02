A,B = map(int, input().split())
if A == B:
    print(A)
    exit()

aa, bb = A, B

A = list(str(bin(A)))[2:]
B = list(str(bin(B)))[2:]
A = ['0']*(len(B)-len(A))+A
print(A, B)
C = ['0']*(len(B))
for i, b in enumerate(B):
    if int(A[i]) + int(b) == 2:
        C[i] = '0'
    elif int(A[i]) + int(b) == 1:
        C[i] = '1'
    else:
        C[i] = '0'

if (bb - aa - 1) % 2 == 0:
    print(int(''.join(C), 2))
    exit()


# print(c)
