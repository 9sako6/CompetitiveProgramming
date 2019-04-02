N, M = map(int, input().split())
graph = [[] for _ in range(N)]
hen = []
for i in range(M):
    a, b = map(int, input().split())
    hen.append([a, b])
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

ans = 0
import copy

def dfs(node, visited, gr):
    visited.append(node)
    for cand in gr[node]:
        if cand not in visited:
            dfs(cand, visited, gr)
    return visited

def gcopy(arr):
    new = []
    for a in arr:
        new.append(copy.copy(a))
    return new

for i in range(M):
    a, b = hen[i]
    g = gcopy(graph)
    g[a-1].remove(b-1)
    g[b-1].remove(a-1)
    visited = []
    ans += 1 if len(dfs(0, visited, g)) == N else 0

print(M-ans)
