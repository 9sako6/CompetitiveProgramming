#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = int64_t;

constexpr int INF = (1 << 30);
constexpr ll INFL = (1LL << 62);
constexpr ll MOD = 1000000007;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

//
// 重み付きUnion-Find Tree size version
//
// verify: AOJ DSL_1_B
//
template <typename T>
struct WeightedUnionFind {
    std::vector<int> data;
    std::vector<T> ws;
    const int n;
    WeightedUnionFind(int num) : data(num, -1), ws(num), n(num) {}
    int find(int k) {
        assert(0 <= k && k < n);
        if (data[k] < 0) return k;
        auto par = find(data[k]);
        ws[k] += ws[data[k]];
        return data[k] = par;
    }
    T weight(int k) {
        assert(0 <= k && k < n);
        find(k);
        return ws[k];
    }
    bool unite(int x, int y, T w) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            std::swap(x, y);
            w *= -1;
        }
        data[x] += data[y];
        data[y] = x;
        ws[y] = w;
        return true;
    }
    int size(int k) {
        assert(0 <= k && k < n);
        return (-data[find(k)]);
    }
    T diff(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return weight(y) - weight(x);
    }
    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return find(x) == find(y);
    }
};

int main() {
    cout << std::fixed << std::setprecision(10);
    int n, m;
    cin >> n >> m;
    WeightedUnionFind<int> uf(n);
    rep(i, m) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        --r;
        if (uf.same(l, r)) {
            if (d != uf.diff(l, r)) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            uf.unite(l, r, d);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
