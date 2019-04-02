#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const ll INFL = (1LL << 62);
const ll MOD = 1000000007;
template <class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
template <class T>
ll mod_pow(ll a, ll n, T mod) {
    mod = (ll)mod;
    ll res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}

struct UnionFind {
    vector<int> data;
    UnionFind(int size) { data.assign(size, -1); }
    int find(int k) {
        if (data[k] < 0) return k;
        return (data[k] = find(data[k]));
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    int size(int k) { return (-data[find(k)]); }
    bool same(int x, int y) { return find(x) == find(y); }
};

struct edge {
    int from, to, cost;
};
struct city {
    int x, y, num;
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<city> cities(N);
    rep(i, N) {
        cin >> cities[i].x >> cities[i].y;
        cities[i].num = i;
    }
    vector<edge> edges;
    sort(all(cities), [](const city &a, const city &b) { return a.x < b.x; });
    rep(i, N - 1) {
        edge e;
        e.cost = min(abs(cities[i + 1].x - cities[i].x),
                     abs(cities[i + 1].y - cities[i].y));
        e.from = cities[i].num;
        e.to = cities[i + 1].num;
        edges.push_back(e);
    }
    sort(all(cities), [](const city &a, const city &b) { return a.y < b.y; });
    rep(i, N - 1) {
        edge e;
        e.cost = min(abs(cities[i + 1].x - cities[i].x),
                     abs(cities[i + 1].y - cities[i].y));
        e.from = cities[i].num;
        e.to = cities[i + 1].num;
        edges.push_back(e);
    }
    sort(all(edges), [](edge a, edge b) { return a.cost < b.cost; });
    UnionFind uf(N);
    int res = 0;
    rep(i, edges.size()) {
        edge e = edges[i];
        if (uf.unite(e.from, e.to)) {
            res += e.cost;
        }
    }
    cout << res << endl;

    return 0;
}
