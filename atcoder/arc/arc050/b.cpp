#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <numeric>
#include <complex>
#include <cassert>
#include <climits>

using namespace std;
using i64 = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const int INF = (1<<30);
const i64 INFL = (1LL<<62);
const i64 MOD = 1000000007;
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> i64 mod_pow(i64 a, i64 n, T mod) { mod=(i64)mod; i64 res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }
void print() { std::cout << std::endl; }
template <typename T, typename... A> void print(const T& first, const A&... rest) { cout << sizeof...(rest) << endl; std::cout << first; if (sizeof...(rest)) std::cout << " "; print(rest...); }
template <typename... A> void print(const A&... rest) { print(rest...); }
template <typename A> void print(const std::vector<A>& v) { std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; }); std::cout << std::endl; }

i64 R, B, x, y;
bool check(i64 z) {
  // z本の花束を作れるか?
  i64 r = R - z, b = B - z;
  if (r < 0 || b < 0) return false;
  i64 num = r / (x - 1) + b / (y - 1);
  return (num >= z);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> R >> B;
  cin >> x >> y;

  i64 ok = 0;
  i64 ng = 1e18;
  while (abs(ok - ng) > 1) {
    i64 mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;

  return 0;
}