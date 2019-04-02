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

vector<i64> crange(i64 cl, i64 cr, i64 xl, i64 xr) {
  vector<i64> res = {0, -1};
  if (xl > cr) {
    // 共通範囲なし
    return res;
  } else if (cr >= xl && cr <= xr) {
    res[0] = xl;
    res[1] = cr;
    return res;
  } else if (cl >= xl && cl <= xr) {
    res[0] = cl;
    res[1] = xr;
    return res;
  } else if (cl <= xl && xr <= cr) {
    res[0] = xl;
    res[1] = xr;
    return res;
  } else if (xl <= cl && cr <= xr) {
    res[0] = cl;
    res[1] = cr;
    return res;
  } else {
    // 共通範囲なし
    return res;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  i64 n;
  cin >> n;
  vector<i64> L(n);
  vector<i64> R(n);
  rep(i, n) { cin >> L[i] >> R[i]; }
  // 範囲最大を探す
  i64 funmax = -1;
  i64 maxid = -1;
  rep(i, n) {
    if (funmax < R[i] - L[i] + 1) {
      maxid = (i64)(i);
      funmax = R[i] - L[i] + 1LL;
    }
  }
  // 範囲最小を探す
  i64 range = INFL;
  i64 minid = -1;
  rep(i, n) {
    vector<i64> tmp = crange(L[maxid], R[maxid], L[i], R[i]);
    i64 kaburi = tmp[1] - tmp[0] + 1;
    if (range > kaburi) {
      range = kaburi;
      minid = i;
    }
  }

  vector<i64> c1 = {L[maxid], R[maxid]};
  // vector<i64> c2 = {L[minid], R[minid]};
  vector<i64> c2 = {1LL, 1000000000};
  rep(i, n) {
    if (i == maxid) continue;
    // if (i == minid) continue;
    i64 fun1, fun2;
    vector<i64> tmp1 = crange(c1[0], c1[1], L[i], R[i]);
    vector<i64> tmp2 = crange(c2[0], c2[1], L[i], R[i]);
    // cout << "--------" << i << endl;
    // print(tmp1);
    // print(tmp2);
    fun1 = tmp1[1] - tmp1[0] + 1LL;
    fun2 = tmp2[1] - tmp2[0] + 1LL;
    if (fun1 > fun2) {
      // i番目の問題をcontest1に配属する
      c1[0] = tmp1[0];
      c1[1] = tmp1[1];
      // cout << "c1:" << i << endl;
    } else {
      c2[0] = tmp2[0];
      c2[1] = tmp2[1];
      // cout << "c2:" << i << endl;
    }
  }
  // print(c1);
  // print(c2);
  i64 ans = (c1[1] - c1[0] + 1LL) + (c2[1] - c2[0] + 1LL);
  cout << ans << endl;
  return 0;
}