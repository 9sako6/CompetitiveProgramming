#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

struct BIT {
  vector<int> bit;
  int n;
  BIT(int n) : bit(vector<int>(n + 1, 0)), n(n) {}
  int sum(int i) {
    if (!i) return 0;
    return bit[i] + sum(i - (i & -i));
  }
  void add(int i, int x) {
    if (i > n) return;
    bit[i] += x;
    add(i + (i & -i), x);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  BIT bitree(n);
  vector<i64> a(n);
  i64 cnt = 0;
  rep(i, n) {
    cin >> a[i];
    bitree.add(a[i], 1);
    cnt += i + 1 - bitree.sum(a[i]);
  }
  cout << cnt << endl;

  return 0;
}
