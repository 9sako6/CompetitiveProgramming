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
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) { cin >> a[i]; }
  queue<vector<int>> q;
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') {
        q.push({i, j, 0});
      }
    }
  }
  int ans = 0;
  while (!q.empty()){
    vector<int> tmp = q.front();
    q.pop();
    int i = tmp[0];
    int j = tmp[1];
    int cnt = tmp[2];
    ans = max(ans, cnt);
    int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    rep(dd, 4){
      int ni = i + d[dd][0];
      int nj = j + d[dd][1];
      if (ni < 0 || ni > h - 1 || nj < 0  || nj > w - 1){
        continue;
      }
      if(a[ni][nj] == '.'){
        q.push({ni, nj, cnt+1});
        a[ni][nj] = '#';
      }
    }
  }
  cout << ans << endl;

  return 0;
}