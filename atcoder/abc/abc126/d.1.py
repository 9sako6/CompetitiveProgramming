import sys
sys.setrecursionlimit(1000000)

N = int(input())
# white: 0, black: 1
g = [[] for _ in range(N)]
for i in range(N-1):
    u, v, w = map(int, input().split())
    g[u-1].append((v-1, w))
    g[v-1].append((u-1, w))
 
visited = [False]*N
def dfs(num, kyori): # 始点からの距離
    if not visited[num]:
        visited[num] = '1' if kyori%2 == 1 else '0'
        for hen in g[num]:
            dfs(hen[0], kyori+hen[1])
    return visited
 
print('\n'.join(dfs(0,0)))