#include <algorithm>
#include <cassert>
#include <climits>
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
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T& a, T b) {
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

struct Edge {
    int from, to, cost;
};

bool visit_zero[2510];
bool visit_N[2510];

void dfs(int k, bool* visit, const vector<int>* v) {
    if (!visit[k]) {
        visit[k] = true;
        for (auto& u : v[k]) {
            if (!visit[u]) {
                dfs(u, visit, v);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> g1[n], g2[n];
    Edge edges[m];
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g1[a].emplace_back(b);
        g2[b].emplace_back(a);
        edges[i] = Edge({a, b, -c + p});
    }

    // 0から到達可能 && n-1へ到達可能な頂点だけ残す
    vector<bool> from_s(n, false), to_g(n, false);
    dfs(0, visit_zero, g1);
    dfs(n - 1, visit_N, g2);
    vector<bool> ok(n, false);
    rep(i, n) { ok[i] = visit_zero[i] && visit_N[i]; }

    // bellman ford
    // https://9sako6.site/posts/2019/11/13/bellman_ford
    int d[n];
    std::fill(d, d + n, INF);
    d[0] = 0;
    rep(i, n) {
        rep(j, m) {
            Edge e = edges[j];
            if (!ok[e.from] || !ok[e.to]) {
                continue;
            }
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                if (i == n - 1) {
                    cout << -1 << endl;
                    return 0;
                }
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    int ans = max(0, -d[n - 1]);
    std::cout << ans << endl;

    return 0;
}