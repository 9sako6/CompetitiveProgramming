#include <bits/stdc++.h>
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_B
using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main() {
  while (true) {
    int n, x;
    cin >> n >> x;
    if (n == 0 && x == 0) return 0;
    int ans = 0;
    map<string, bool> used;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int k = x - i - j;
        vector<int> a({i, j, k});
        sort(all(a));
        string cand = "";
        rep(i, 3) { cand += to_string(a[i]) + ","; }
        if (0 < k && k < n && k != j && k != i && !used[cand]) {
          ++ans;
          used[cand] = true;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}