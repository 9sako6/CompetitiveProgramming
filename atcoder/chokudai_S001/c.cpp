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
  vector<string> a(n);
  string ans = "";
  rep(i, n) {
    cin >> a[i];
    ans = ans + a[i];
    if (i != n-1){
      ans = ans + ",";
    }
  }
  cout << ans << endl;

  return 0;
}