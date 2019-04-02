#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define int i64
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

#undef int
int main() {
#define int i64
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) { cin >> a[i][j]; }
  }
  int ans = 0;
  rep(k1, m) {
    for (int k2 = k1 + 1; k2 < m; ++k2) {
      int s = 0;
      rep(i, n) { s += max(a[i][k1], a[i][k2]); }
      ans = max(ans, s);
    }
  }
  cout << ans << endl;

  return 0;
}