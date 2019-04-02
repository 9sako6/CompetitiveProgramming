class UnionFind:
    def __init__(self, n):
        """ノード数nの配列を作る

        親の番号を格納する
        -> 自分が根だった場合は、-(その集合のサイズ)とする
        作るときはparentの値を全て-1にする
        こうすると全てバラバラになる
        """
        self.parent = [-1 for _ in range(n)]

    def root(self, x):
        """要素xの根の番号を返す
        """
        if self.parent[x] < 0:
            # 自分が根
            return x
        # 要素xの親を要素xの根に変えておく
        # 次の呼び出しが早くなる
        self.parent[x] = self.root(self.parent[x])
        return self.parent[x]

    def size(self, x):
        """要素xの所属するグループの頂点数を調べる

        根のparentにサイズが格納されている
        """
        return -self.parent[self.root(x)]

    def merge(self, x, y):
        """xとyを結合する
        """
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False

        #大きい方(x)に小さい方(y)をくっつけたい
        if self.size(x) < self.size(y):
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x
        return True


n,m = map(int,input().split())
a, b = [0]*m, [0]*m
for i in range(m):
    a[i],b[i] = map(int, input().split())
    a[i] -= 1
    b[i] -= 1

ans = [0 for _ in range(m)]
ans[m-1] = n*(n-1)//2

uf = UnionFind(n)
i = 1
for ai, bi in zip(a[::-1], b[::-1]):
    id = m-1-i
    if id < 0:
        break
    if uf.root(ai) == uf.root(bi):
        ans[id] = ans[id+1]
    else:
        sa = uf.size(ai)
        sb = uf.size(bi)
        ans[id] = ans[id+1] - sa*sb
        uf.merge(ai, bi)
    i += 1

print('\n'.join(map(str, ans)))
