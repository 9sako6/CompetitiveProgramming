from sys import stdin
def input():
    return stdin.readline()[:-1]

class UnionFind:
    def __init__(self, n):
        self.parent = [-1 for _ in range(n)]

    def root(self, x):
        if self.parent[x] < 0:
            return x
        self.parent[x] = self.root(self.parent[x])
        return self.parent[x]

    def size(self, x):
        return -self.parent[self.root(x)]

    def merge(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False

        if self.size(x) < self.size(y):
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x
        return True

N,M=map(int, input().split())
aby=[list(map(int, input().split())) for _ in range(M)]
Q=int(input())
ivw = [[i] + list(map(int, input().split())) for i in range(Q)]

aby.sort(key=lambda x: x[2], reverse=True)
ivw.sort(key=lambda x: x[2], reverse=True)

ans = [0]*Q
uf = UnionFind(N)
j = 0
for i,v,w in ivw:
    while j < M and w < aby[j][2]:
        uf.merge(aby[j][0]-1, aby[j][1]-1)
        j += 1
    ans[i] = uf.size(v-1)

print('\n'.join(map(str, ans)))