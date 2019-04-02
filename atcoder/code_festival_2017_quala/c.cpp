#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  int cnt[26] = {};
  rep(i, h) {
    string a;
    cin >> a;
    for (auto& ai : a) {
      cnt[ai - 'a']++;
    }
  }
  if (!(h & 1) && !(w & 1)) {
    rep(i, 26) {
      if (cnt[i] % 4 == 0) {
        continue;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  } else {
    int cnt_odd = 0;
    int cnt_mod_2 = 0;
    rep(i, 26) {
      if (cnt[i] & 1) {
        cnt_odd++;
        cnt[i]--;
      }
      if (cnt[i] % 4 == 2) {
        cnt_mod_2++;
        cnt[i] -= 2;
      }
    }
    if ((h & 1) && (w & 1) &&
        (cnt_odd != 1 || !(cnt_mod_2 <= (h / 2) + (w / 2)))) {
      cout << "No" << endl;
      return 0;
    } else if ((h * w % 2 == 0) && !(cnt_mod_2 <= ((w & 1) ? h / 2 : w / 2))) {
      cout << "No" << endl;
      return 0;
    }
    rep(i, 26) {
      if (cnt[i] % 4 != 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}