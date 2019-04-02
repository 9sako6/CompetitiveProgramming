N, M, X = map(int, input().split())
A = list(map(int, input().split()))

arr = [0]*(N+1)

for a in A:
    arr[a] = 1

ans = min(sum(arr[1:X]), sum(arr[X:-1]))

print(ans)
