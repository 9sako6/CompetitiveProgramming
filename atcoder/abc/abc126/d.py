N = int(input())
# white: 0, black: 1
g = [[] for _ in range(N)]
for i in range(N-1):
    u, v, w = map(int, input().split())
    g[u-1].append((v-1, w))
    g[v-1].append((u-1, w))

visited = [False]*N
from collections import deque

q = deque()
q.append([0, 0])
while q:
    num, kyori = q.pop()
    visited[num] = '1' if kyori%2 == 1 else '0'
    for hen in g[num]:
        if not visited[hen[0]]:
            q.append([hen[0], kyori+hen[1]]) 

print('\n'.join(visited))