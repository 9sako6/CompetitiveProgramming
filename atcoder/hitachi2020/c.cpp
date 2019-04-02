#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char *argv[]) {
    main_sub();
    return 0;
}
// int を int64_t にする
// g++ に -DUSE_STRICT_INT をつけるか、
// 下のコメントアウトを外すと無効化
#define USE_STRICT_INT
using i64 = int64_t;
#ifndef USE_STRICT_INT
#define int i64
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF = (1 << 30);
constexpr i64 INFL = (1LL << 62);
constexpr i64 MOD = 1000000007;

template <typename G>
struct DoublingLowestCommonAncestor {
    const int LOG;
    vector<int> dep;
    vector<int> len;
    const G &g;
    vector<vector<int>> table;

    DoublingLowestCommonAncestor(const G &g)
        : g(g),
          dep(g.size()),
          LOG(32 - __builtin_clz(g.size())),
          len(g.size()) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d, int l) {
        table[0][idx] = par;
        dep[idx] = d;
        len[idx] = l;
        for (auto &to : g[idx]) {
            if (to != par) dfs(to, idx, d + 1, l + 1);
        }
    }

    void build() {
        dfs(0, -1, 0, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < (int)table[k].size(); i++) {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                    table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T &first, const A &... rest) {
    cout << sizeof...(rest) << endl;
    std::cout << first;
    if (sizeof...(rest)) std::cout << " ";
    print(rest...);
}
template <typename... A>
void print(const A &... rest) {
    print(rest...);
}
template <typename A>
void print(const std::vector<A> &v) {
    std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
    std::cout << std::endl;
}

void main_sub(void) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DoublingLowestCommonAncestor<vector<vector<int>>> lca(g);
    lca.build();
    rep(i, n) {
        rep(j, n) {
            int z = lca.query(i, j);
            int d = lca.len[i] + lca.len[j] - 2 * lca.len[z];
            cout << "(" << i + 1 << ", " << j + 1 << "): " << z + 1 << endl;
            cout << d << endl;
        }
    }
    print(lca.len);
    // deque<pair<int, int>> q;
    // q.push_back({0, 0});

    return;
}