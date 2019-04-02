#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char* argv[]) {
    main_sub();
    return 0;
}
// int を int64_t にする
// g++ に -DUSE_STRICT_INT をつけるか、
// 下のコメントアウトを外すと無効化
// #define USE_STRICT_INT
using i64 = int64_t;
#ifndef USE_STRICT_INT
#define int i64
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF = (1 << 30);
constexpr i64 INFL = (1LL << 62);
constexpr i64 MOD = 1000000007;

void main_sub(void) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n) {
        int u, k;
        cin >> u;
        u--;
        cin >> k;
        rep(j, k) {
            int v;
            cin >> v;
            v--;
            g[u].push_back(v);
        }
    }
    queue<pair<int, int>> q;
    vector<int> dist(n, INF);
    q.push({0, 0});
    while (!q.empty()) {
        int from, d;
        tie(from, d) = q.front();
        q.pop();
        if (dist[from] > d) {
            dist[from] = d;
        }
        for (auto& to : g[from]) {
            if (dist[to] > d + 1) {
                dist[to] = d + 1;
                q.push({to, d + 1});
            }
        }
    }
    rep(i, n) {
        cout << i + 1 << " " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }

    return;
}