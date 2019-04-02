#include <iostream>
#include <vector>
using namespace std;
using i64 = int64_t;
#define INF 1e+9
#define MAX_N 1000

i64 dp[MAX_N];
i64 n;
vector<i64> a;

void solve() {
  fill(dp, dp + n, INF);
  for (i64 i = 0; i < n; ++i) {
    *lower_bound(dp, dp + n, a[i]) = a[i];
  }
  cout << lower_bound(dp, dp + n, INF) - dp << endl;
}

int main() {
  cin >> n;
  a.resize(n);
  for (i64 i = 0; i < n; ++i) cin >> a[i];
  solve();
}