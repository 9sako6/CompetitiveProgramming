A, B = map(int, input().split())

cnt = 0

for i in range(A, B+1):
    tmp = list(str(i))
    if tmp[0] == tmp[-1] and tmp[1] == tmp[-2]:
        cnt += 1

print(cnt)

