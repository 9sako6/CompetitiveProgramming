#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = int64_t;

constexpr int INF = (1 << 30);
constexpr ll INFL = (1LL << 62);
constexpr ll MOD = 1000000007;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int a[1010][1010];
ll dp[1010][1010];
int h, w;
ll rec(int y, int x) {
    if (dp[y][x] != -1) return dp[y][x];
    ll ret = 1;
    rep(i, 4) {
        int ny = y + dy[i], nx = x + dx[i];
        if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
        if (a[y][x] < a[ny][nx]) {
            ret += rec(ny, nx);
            ret %= MOD;
        }
    }

    return dp[y][x] = ret;
}

int main() {
    cout << std::fixed << std::setprecision(10);
    cin >> h >> w;
    rep(i, h) rep(j, w) scanf("%d", &a[i][j]);
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    rep(i, h) rep(j, w)(ans += rec(i, j)) %= MOD;
    cout << ans << endl;
    return 0;
}
