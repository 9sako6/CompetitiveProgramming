#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

bool check(i64 x, i64 k, const vector<i64> &a) {
  // x 以下の数がk個以上ある？
  i64 cnt = 0;  // x以下の数の個数
  i64 n = a.size();

  rep(i, n) {
    i64 ci = 0;
    long double t = 0;
    if (a[i] == 0) {
      // 0とかけてx以下になる個数
      if (x < 0) {
      } else {
        ci = n - 1 - i;
      }
    } else {
      t = x / (long double)a[i];
      if (a[i] > 0) {
        // t以下の数の個数
        ci = upper_bound(a.begin() + i + 1, a.end(), t) - (a.begin() + i + 1);
      } else {
        // t以上の数の個数
        ci = a.end() - lower_bound(a.begin() + i + 1, a.end(), t);
      }
    }
    cnt += ci;
    // cout << "a[i]:" << a[i] << ", x:" << x << ", t:" << t << ", ci:" << ci
    //      << endl;
  }

  return cnt >= k;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  rep(i, n) { cin >> a[i]; }
  sort(all(a));
  const i64 MAX = 1e18 * 2;
  i64 ok = MAX;
  i64 ng = -MAX;
  while (abs(ok - ng) > 1) {
    i64 mid = (ok + ng) / 2;
    if (check(mid, k, a)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
  return 0;
}