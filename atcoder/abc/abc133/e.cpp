#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll MOD = 1e9 + 7;

ll dfs(int k, const vector<vector<int>> &g, int now, int from) {
    int can_use_color_num = (from == -1) ? k - 1 : k - 2;
    if (k < (int)g[now].size()) {
        return 0;
    } else {
        ll res = 1;
        for (auto &e : g[now]) {
            if (e == from) continue;
            res *= can_use_color_num;
            can_use_color_num--;
            res %= MOD;
        }
        for (auto &e : g[now]) {
            if (e == from) continue;
            res *= dfs(k, g, e, now);
            res %= MOD;
        }
        return res;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = k * dfs(k, g, 0, -1);
    ans %= MOD;
    cout << ans << endl;
}
