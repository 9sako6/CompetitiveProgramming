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
using i64 = long long;
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
int n, q;
string s;
char t[200200];
char d[200200];
int check_drop(int k) {
  rep(i, q) {
    if (t[i] != s[k]) continue;
    k += (d[i] == 'L' ? -1 : 1);
    if (k < 0) return -1;
    if (k >= n) return 1;
  }
  return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> q;
  cin >> s;
  rep(i, q) { cin >> t[i] >> d[i]; }

  int h = n;
  int l = -1;
  while (abs(h - l) > 1) {
    int mid = (h + l) / 2;
    if (check_drop(mid) == -1) {
      l = mid;
    } else {
      h = mid;
    }
  }
  int left = h;
  h = n;
  l = -1;
  while (abs(h - l) > 1) {
    int mid = (h + l) / 2;
    if (check_drop(mid) == 1) {
      h = mid;
    } else {
      l = mid;
    }
  }
  int right = n - 1 - l;
  cout << n - (left + right) << endl;
  return 0;
}