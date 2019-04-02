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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a.at(i); }
  int ans = 0;
  int l = 0;
  rep(i, n) {
    if (a[i] == 0) {
      if (i == 0) {
        l = 1;
      } else {
        ans += accumulate(a.begin() + l, a.begin() + i, 0) / 2;
        l = i + 1;
      }
    }
  }
  ans += accumulate(a.begin() + l, a.begin() + n, 0) / 2;
  cout << ans << endl;
  return 0;
}