#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < (int)s.size(); ++i) {
    if (s[i - 1] > s[i]) {
      s.erase(i - 1, 1);
      cout << s << endl;
      return 0;
    }
  }
  cout << s.substr(0, s.size() - 1) << endl;
  return 0;
}