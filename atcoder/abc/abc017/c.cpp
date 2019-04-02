#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int l[n], r[n], s[n];
  rep(i, n) { scanf("%d %d %d", l + i, r + i, s + i); }
  int ans = -1;
  for (int x = 1; x <= m; ++x) {
    int score = 0;
    rep(i, n) {
      if (x < l[i] || r[i] < x) score += s[i];
    }
    ans = max(ans, score);
  }
  printf("%d\n", ans);

  return 0;
}