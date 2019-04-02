#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;
template <class T>
i64 mod_pow(i64 a, i64 n, T mod) {
  mod = (i64)mod;
  i64 res = 1, p = a % mod;
  while (n) {
    if (n & 1) res = res * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  i64 n;
  cin >> n;
  vector<string> a(n);
  rep(i, n) { cin >> a[i]; }
  string num = "";
  rep(i, n) { num += a[i]; }
  i64 ans = 0;
  rep(i, num.size()) {
    i64 m = num[i] - '0';
    ans += m * mod_pow(10, ((i64)(num.size()) - (i + 1)), MOD);
    ans %= MOD;
  }
  std::cout << ans << endl;

  return 0;
}