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
using i64 = int64_t;
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
  int n, m;
  cin >> n >> m;
  vector<int> node(n, 0);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    node[a-1]++;
    node[b-1]++;
  }
  rep(i, n){
    if(node[i] & 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;


  return 0;
}