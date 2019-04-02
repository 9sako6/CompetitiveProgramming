#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;
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
int h, w;
vector<string> s;
int bfs(int sy, int sx, int gy, int gx) {
  vector<vector<int>> bfs_map(h, vector<int>(w, INF));
  // rep(i, h) rep(j, w) bfs_map[i][j] = INF;
  bfs_map[sy][sx] = 0;
  queue<vector<int>> q;
  q.push({sy, sx, 0});
  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  while (!q.empty()) {
    vector<int> tmp = q.front();
    q.pop();
    int x = tmp[1];
    int y = tmp[0];
    int dist = tmp[2];
    rep(i, 4) {
      int ny = y + d[i][1];
      int nx = x + d[i][0];
      if (nx >= 0 && nx < w && ny >= 0 && ny < h && s[ny][nx] != '#') {
        if (bfs_map[ny][nx] > dist + 1) {
          bfs_map[ny][nx] = dist + 1;
          q.push({ny, nx, dist + 1});
        }
      }
    }
  }
  // rep(i, h) { print(bfs_map[i]); }
  // cout << bfs_map[gy][gx] << endl;
  return bfs_map[gy][gx];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  rep(i, h) {
    string a;
    cin >> a;
    s.push_back(a);
  };
  // rep(i, h) cout << s[i] << endl;
  int ans = -1;
  rep(sy, h) {
    rep(sx, w) {
      rep(gy, h) {
        rep(gx, w) {
          if (s[sy][sx] != '#' && s[gy][gx] != '#') {
            ans = max(ans, bfs(sy, sx, gy, gx));
          }
        }
      }
    }
  }
  // cout << INF << endl;
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}