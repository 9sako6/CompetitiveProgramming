#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;
// int ex[5001][5001];
vector<int> ex[5001];

inline bool uchi(int z) { return (0 <= z && z <= 5000); }

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    x[i] = a;
    y[i] = b;
    ex[a].push_back(b);
  }
  rep(i, 5001) { sort(all(ex[i])); }
  int ans = 0;
  rep(i, n) {
    int ax = x[i];
    int ay = y[i];
    for (int j = i + 1; j < n; ++j) {
      int bx = x[j];
      int by = y[j];
      int vx = bx - ax;
      int vy = by - ay;
      int c1x = vy + ax;
      int c1y = -vx + ay;
      int d1x = vx + vy + ax;
      int d1y = vy - vx + ay;
      int c2x = -vy + ax;
      int c2y = vx + ay;
      int d2x = vx - vy + ax;
      int d2y = vy + vx + ay;
      if (uchi(c1x) && uchi(c1y) && uchi(d1x) && uchi(d1y)) {
        if (binary_search(all(ex[c1x]), c1y) &&
            binary_search(all(ex[d1x]), d1y)) {
          ans = max(ans, vx * vx + vy * vy);
        }
      }
      if (uchi(c2x) && uchi(c2y) && uchi(d2x) && uchi(d2y)) {
        if (binary_search(all(ex[c2x]), c2y) &&
            binary_search(all(ex[d2x]), d2y)) {
          ans = max(ans, vx * vx + vy * vy);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}