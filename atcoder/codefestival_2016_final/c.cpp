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

struct UnionFindSize {
    std::vector<int> data;
    const int n;
    UnionFindSize(int num) : data(num, -1), n(num) {}
    int find(int k) {
        assert(0 <= k && k < n);
        if (data[k] < 0) return k;
        return (data[k] = find(data[k]));
    }
    bool unite(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = find(x), y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    int size(int k) {
        assert(0 <= k && k < n);
        return (-data[find(k)]);
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
    UnionFindSize uf(m + n);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int l;
            cin >> l;
            uf.unite(l - 1, m + i);
        }
    }
    bool flag = true;
    rep(i, n - 1) {
        if (!uf.same(m + i, m + i + 1)) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
