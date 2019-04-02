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
  string s;
  cin >> s;
  int cnt = 0;
  int tmp = 0;
  char acgt[4] = {'A', 'C', 'G', 'T'};
  rep(i, s.size()) {
    bool flag = true;
    rep(j, 4) {
      if (s[i] == acgt[j]) flag = false;
    }
    if (flag) {
      cnt = max(cnt, tmp);
      tmp = 0;
    } else {
      ++tmp;
    }
  }
  cnt = max(cnt, tmp);
  cout << cnt << endl;
  return 0;
}