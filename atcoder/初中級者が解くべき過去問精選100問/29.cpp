#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char* argv[]) {
    main_sub();
    return 0;
}
// int を int64_t にする
// g++ に -DUSE_STRICT_INT をつけるか、
// 下のコメントアウトを外すと無効化
// #define USE_STRICT_INT
using i64 = int64_t;
#ifndef USE_STRICT_INT
#define int i64
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF = (1 << 30);
constexpr i64 INFL = (1LL << 62);
constexpr i64 MOD = 1000000007;

void main_sub(void) {
    int h, w;
    cin >> h >> w;
    int sy, sx;
    cin >> sy >> sx;
    sy--;
    sx--;
    int gy, gx;
    cin >> gy >> gx;
    gy--;
    gx--;
    vector<string> c(h);
    vector<vector<int>> bfs_map(h, vector<int>(w, INF));
    bfs_map[sy][sx] = 0;
    rep(i, h) { cin >> c[i]; }
    bool flag_goal = false;
    int dd[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, 0});
    while (q.size()) {
        if (flag_goal) break;
        pair<int, int> tmp;
        int d;
        int y, x;
        tie(tmp, d) = q.front();
        q.pop();
        tie(y, x) = tmp;
        rep(i, 4) {
            int ny = y + dd[i][0];
            int nx = x + dd[i][1];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && c[ny][nx] != '#') {
                if (bfs_map[ny][nx] > d + 1) {
                    bfs_map[ny][nx] = d + 1;
                    q.push({{ny, nx}, d + 1});
                }
            }
        }
    }
    cout << bfs_map[gy][gx] << endl;

    return;
}