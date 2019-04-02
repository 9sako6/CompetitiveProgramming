#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;
void print() { std::cout << std::endl; }
template <typename T, typename... A> void print(const T& first, const A&... rest) { cout << sizeof...(rest) << endl; std::cout << first; if (sizeof...(rest)) std::cout << " "; print(rest...); }
template <typename... A> void print(const A&... rest) { print(rest...); }
template <typename A> void print(const std::vector<A>& v) { std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; }); std::cout << std::endl; }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  print(a);
  return 0;
}