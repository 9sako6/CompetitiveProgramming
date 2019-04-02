#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  for (int b = 0; b < (1 << n); ++b) {
    bitset<12> bs(b);
    bool flag = true;  // 派閥を作れる
    int cnt = bs.count();
    vector<int> cands;
    rep(j, n) {
      if (bs[j]) {
        cands.push_back(j);
      }
    }
    for (auto& c : cands) {
      for (auto& d : cands) {
        if (c == d) continue;
        if (g[c].end() == find(all(g[c]), d)) {
          flag = false;
          break;
        }
      }
    }
    if (flag) ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}