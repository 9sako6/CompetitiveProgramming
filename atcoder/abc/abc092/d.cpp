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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  char grid[100][100];
  rep(col, 100){
    rep(row, 100){
      if(col < 50){
        grid[col][row] = '#';
      }else{
        grid[col][row] = '.';
      }
    }
  }
  // 白塗り
  int x = 1, y = 1;
  rep(i, a-1){
    grid[y][x] = '.';
    y += 2;
    if(y >= 49){
      y = 1;
      x += 2;
    }
  }
  x = 1, y = 51;
  rep(i, b-1){
    grid[y][x] = '#';
    y += 2;
    if (y > 100){
      y = 51;
      x += 2;
    }
  }
  cout << 100 << " " << 100 << endl;
  rep(y, 100)rep(x, 100){
    cout << grid[y][x];
    if(x == 99){
      cout << "\n";
    }
  }



  return 0;
}