#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
// #define int i64
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

template <typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;

  int sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) { seg[k + sz] = x; }

  void build() {
    for (int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const { return seg[k + sz]; }

  template <typename C>
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while (a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template <typename C>
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if (a <= 0) {
      if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        Monoid nxt = f(L, seg[a]);
        if (check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template <typename C>
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if (b >= sz) {
      if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        Monoid nxt = f(seg[--b], R);
        if (check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

// #undef int
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<SegmentTree<int>> segs;
  rep(i, 26) {
    SegmentTree<int> seg(n, [](int a, int b) { return (a + b); }, 0);
    // seg.build();
    segs.emplace_back(seg);
  }
  rep(i, n) {
    int c = s[i] - 'a';
    segs[c].update(i, 1);
  }
  rep(i, 26) { segs[i].build(); }
  // query
  int q;
  cin >> q;
  rep(i, q) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      char c;
      cin >> c;
      int original = s[b - 1] - 'a';
      int to = c - 'a';
      if (original == to) continue;
      segs[original].update(b - 1, 0);
      // segs[original].build();
      segs[to].update(b - 1, 1);
      // segs[to].build();
      s[b - 1] = c;
    } else {
      int c;
      cin >> c;
      int ans = 0;
      rep(j, 26) {
        if (segs[j].query(b - 1, c) > 0) {
          ++ans;
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}