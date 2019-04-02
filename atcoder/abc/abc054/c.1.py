from itertools import permutations
n, m = map(int, input().split())
es = set()
for _ in range(m):
    u, v = map(int, input().split())
    es |= {(u-1, v-1), (v-1, u-1)}
print(es)