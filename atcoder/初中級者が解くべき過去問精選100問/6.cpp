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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, 1001) {
    int c[3] = {i / 100, i / 10 % 10, i % 10};
    int index[3] = {-1, -1, -1};
    rep(j, 3) {
      if (j != 0 && index[j] == -1) break;
      for (int k = index[j] + 1; k < n; ++k) {
        if (s[k] == (c[j] + '0')) {
          if (j == 2) {
            ++ans;
            break;
          } else {
            index[j + 1] = k;
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}