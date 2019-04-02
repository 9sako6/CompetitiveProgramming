N = int(input())
A = list(map(int, input().split()))

INF = 10**9
min_cost = INF

for target in range(min(A), max(A)+1):
    tmp_cost = 0
    for i in range(N):
        tmp_cost += (target-A[i])**2
    if tmp_cost <= min_cost:
        min_cost = tmp_cost

print(min_cost)
