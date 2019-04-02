N, M, C = map(int, input().split())
B = list(map(int, input().split()))
cnt = 0
for i in range(N):
    A = list(map(int, input().split()))
    ABsum = 0
    for j in range(M):
        ABsum += A[j]*B[j]
    ABsum += C
    if ABsum > 0:
        cnt += 1

print(cnt)
