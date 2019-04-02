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
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
i64 mod_pow(i64 a, i64 n, T mod) {
  mod = (i64)mod;
  i64 res = 1, p = a % mod;
  while (n) {
    if (n & 1) res = res * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return res;
}
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T& first, const A&... rest) {
  cout << sizeof...(rest) << endl;
  std::cout << first;
  if (sizeof...(rest)) std::cout << " ";
  print(rest...);
}
template <typename... A>
void print(const A&... rest) {
  print(rest...);
}
template <typename A>
void print(const std::vector<A>& v) {
  std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
  std::cout << std::endl;
}
i64 bit[50];  // bit[i] := i桁目が1のやつの個数
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  rep(i, n) cin >> a[i];
  vector<i64> s(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + a[i];
  }
  vector<i64> cands;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      cands.push_back(s[j + 1] - s[i]);
    }
  }
  // print(cands);

  for (int i = 49; i >= 0; --i) {
    vector<i64> cands2;
    for (auto& c : cands) {
      if (c & (1LL << i)) {
        cands2.push_back(c);
      }
    }
    if ((i64)cands2.size() >= k) {
      cands = move(cands2);
    }
  }
  i64 ans =
      accumulate(all(cands), cands[0], [](i64 acc, i64 i) { return acc & i; });
  cout << ans << endl;

  return 0;
}