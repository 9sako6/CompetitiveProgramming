N = int(input())
A = list(map(int, input().split()))

cnt = 0
flag = True
for i, a in enumerate(A):
    if i == 0:
        continue
    if a == A[i-1] and flag:
        cnt += 1
        flag = False
    else:
        flag = True

print(cnt)
