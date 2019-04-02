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
  i64 n, k;
  cin >> n >> k;

  vector<i64> a(n);
  rep(i, n) { cin >> a[i]; }
  vector<i64> s(n + 1, 0);
  rep(i, n) { s[i + 1] = s[i] + a[i]; }
  map<i64, i64> mp;
  i64 ans = 0;

  for (i64 j = 0; j <= n; ++j) {
    int now = (s[j] - j) % k;
    if (j >= k) {
      int left = (s[j - k] - j) % k;
      if (left < 0) left += k;
      mp[left]--;
    }
    ans += mp[now];
    mp[now]++;
  }
  cout << ans << endl;

  return 0;
}