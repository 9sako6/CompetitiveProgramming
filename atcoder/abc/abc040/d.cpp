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
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T& first, const A&... rest) {
    cout << sizeof...(rest) << endl;
    std::cout << first;
    if (sizeof...(rest)) std::cout << " ";
    print(rest...);
}
template <typename... A>
void print(const A&... rest) {
    print(rest...);
}
template <typename A>
void print(const std::vector<A>& v) {
    std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
    std::cout << std::endl;
}
int main() {
    cout << std::fixed << std::setprecision(10);
    int n, m;
    cin >> n >> m;
    WeightedUnionFind<int> uf(n);
    vector<vector<int>> bridges(m, vector<int>(3));
    rep(i, m) {
        int a, b, y;
        cin >> a >> b >> y;
        --a;
        --b;
        bridges[i] = {a, b, y};
    }
    auto comp = [](const vector<int> a, const vector<int> b) {
        return a[2] > b[2];
    };
    sort(all(bridges), comp);

    int q;
    cin >> q;
    int nth = 0;
    vector<int> ans(q);
    vector<vector<int>> p(q, vector<int>(3));
    rep(i, q) {
        int v, w;
        cin >> v >> w;
        --v;
        p[i] = {i, v, w};
    }
    sort(all(p), comp);
    rep(i, q) {
        auto pi = p[i];
        while (nth < m && bridges[nth][2] > pi[2]) {
            uf.unite(bridges[nth][0], bridges[nth][1], 1);
            ++nth;
        }
        ans[pi[0]] = uf.size(pi[1]);
    }

    // rep(i, m) { print(bridges[i]); }
    // rep(i, q) { print(p[i]); }
    rep(i, q) { cout << ans[i] << endl; }
    return 0;
}
