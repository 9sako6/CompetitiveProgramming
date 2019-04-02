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

N,M=map(int, input().split())

AB= [list(map(int, input().split())) for _ in range(M)]
ans=0
for i in range(M):
    uf = UnionFind(N)
    hens = AB[0:i]+AB[i+1:]
    for hen in hens:
        x,y = hen
        uf.merge(x-1, y-1)

    if uf.size(0) != N:
        ans+=1
print(ans)
