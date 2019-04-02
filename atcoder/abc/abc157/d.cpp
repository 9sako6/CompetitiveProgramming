#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
// #define int i64
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

struct UnionFindSize {
  std::vector<int> data;
  const int n;
  UnionFindSize(int num) : data(n, -1), n(num) { data.resize(n); }
  int find(int k) {
    assert(0 <= k && k < n);
    if (data[k] < 0) return k;
    return (data[k] = find(data[k]));
  }
  bool unite(int x, int y) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    x = find(x), y = find(y);
    if (x == y) return false;
    if (data[x] > data[y]) std::swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
  int size(int k) {
    assert(0 <= k && k < n);
    return (-data[find(k)]);
  }
  bool same(int x, int y) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    return find(x) == find(y);
  }
};

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
// #undef int
int main() {
  // #define int i64
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  UnionFindSize uf(n);
  vector<vector<int>> gf(n);
  vector<vector<int>> gb(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a, b);
    gf[a].push_back(b);
    gf[b].push_back(a);
  }
  vector<int> d(n, 0);
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gb[a].push_back(b);
    gb[b].push_back(a);
    if (uf.same(a, b)) {
      d[a]++;
      d[b]++;
    }
  }
  vector<int> ans(n);
  rep(i, n) { ans[i] = max(0, uf.size(i) - 1 - (int)(gf[i].size()) - d[i]); }
  rep(i, n) {
    cout << ans[i];
    if (i != n) {
      cout << " ";
    }
  }
  cout << endl;
  // cout << "f" << endl;

  // rep(i, n) { print(gf[i]); }
  // cout << "block" << endl;
  // rep(i, n) { print(gb[i]); }
  // print(uf.data);
  return 0;
}