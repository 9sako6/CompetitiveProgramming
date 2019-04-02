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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }
  int max = 0;
  int ans = 0;
  rep(i, n) {
    if (max < a[i]) {
      ans++;
      max = a[i];
    }
  }
  cout << ans << endl;

  return 0;
}