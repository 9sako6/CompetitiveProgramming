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
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T &first, const A &... rest) {
  cout << sizeof...(rest) << endl;
  std::cout << first;
  if (sizeof...(rest)) std::cout << " ";
  print(rest...);
}
template <typename... A>
void print(const A &... rest) {
  print(rest...);
}
template <typename A>
void print(const std::vector<A> &v) {
  std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
  std::cout << std::endl;
}

int bfs(int n, int sy, int sx, int gy, int gx, const vector<int> &ry,
        const vector<int> &rx, const vector<int> &by, const vector<int> &bx,
        const vector<vector<char>> &f) {
  queue<vector<int>> q;
  q.push({sy, sx, 0});
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  while (!q.empty()) {
    vector<int> tmp = q.front();
    q.pop();
    int y = tmp[0];
    int x = tmp[1];
    int len = tmp[2];
    if (y == gy && x == gx) {
      return len;
    }
    visited[y][x] = true;
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // dy, dx
    rep(i, 4) {
      int ny = d[i][0] + y;
      int nx = d[i][1] + x;
      if (ny >= 0 && ny < n && nx >= 0 && nx < n && f[ny][nx] != '#' && visited[ny][nx] == false) {
        q.push({ny, nx, len + 1});
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, b;
  cin >> n >> m >> b;
  int gy, gx;
  cin >> gy >> gx;
  vector<vector<char>> f(n, vector<char>(n, '.'));
  f[gy][gx] = 'G';
  vector<int> ry(n);
  vector<int> rx(n);
  vector<char> c(n);
  rep(i, m) {
    cin >> ry[i] >> rx[i] >> c[i];
    f[ry[i]][rx[i]] = c[i];
  }
  vector<int> by(n);
  vector<int> bx(n);
  rep(i, b) {
    cin >> by[i] >> bx[i];
    f[by[i]][bx[i]] = '#';
  }
  // rep(i, n) { print(f[i]); }
  // make map
  vector<int> ansy;
  vector<int> ansx;
  vector<int> ansd;

  int k = ansy.size();
  std::cout << k << std::endl;
  rep(i, k) { printf("%d %d %c\n", ansy[i], ansx[i], ansd[i]); }

  return 0;
}

/*
sample 1:
5 3 3
2 4
1 1 R
3 1 U
3 2 L
1 3
3 0
4 2




*/