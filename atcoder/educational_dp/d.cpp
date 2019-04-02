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
int n, u;
vector<int> w;
vector<int> v;
int dp[110][100100];
int search(int i, int ui) {
    if (i == n) {
        return 0;
    }
    if (dp[i][ui] != -1) {
        return dp[i][ui];
    }
    if (ui < w[i]) {
        return dp[i][ui] = search(i + 1, ui);
    } else {
        return dp[i][ui] =
                   max(search(i + 1, ui), search(i + 1, ui - w[i]) + v[i]);
    }
}

void main_sub(void) {
    cin >> n >> u;
    w.resize(n);
    v.resize(n);
    rep(i, n + 1) {
        rep(j, u + 1) { dp[i][j] = -1; }
    }
    rep(i, n) { cin >> w[i] >> v[i]; }
    cout << search(0LL, u) << endl;
    return;
}