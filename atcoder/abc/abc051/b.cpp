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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k, s;
  int ans = 0;
  cin >> k >> s;
  rep(x, k + 1) {
    rep(y, k + 1) {
      int z = s - x - y;
      if(z <= k && z >= 0){
        ans++;
        // printf("%d+%d+%d=%d\n", x, y, z, s);
      }
    }
  }
  cout << ans << endl;
  return 0;
}