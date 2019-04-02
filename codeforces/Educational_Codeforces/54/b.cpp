#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

template <typename T>
vector<T> divs(T n) {
  vector<T> res;
  T i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) {
        res.push_back(n / i);
      }
      n /= i;
    }
    ++i;
  }
  return res;
}

template <typename T>
bool is_prime(T n) {
  if (n < 2) return false;
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  i64 n;
  cin >> n;
  if (!(n & 1)) {
    cout << n / 2 << endl;
    return 0;
  }
  vector<i64> ds = divs(n);
  sort(all(ds));
  for (auto &d : ds) {
    if (is_prime(d)) {
      n -= d;
      break;
    }
  }
  cout << n / 2 + 1 << endl;

  return 0;
}