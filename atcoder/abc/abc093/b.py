A, B, K = map(int, input().split())

if B - A < K*2:
    for i in range(A, B+1):
        print(i)
else:
    for a in range(A, A+K):
        if a > B:
            break
        print(a)

    for b in range(B-K+1, B+1):
        print(b)
