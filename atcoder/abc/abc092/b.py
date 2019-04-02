N = int(input())
D, X = map(int, input().split())
A = [int(input()) for i in range(N)]

cnt = 0
for a in A:
    for i in range(1, D+1, a):
        cnt += 1

print(cnt + X)
