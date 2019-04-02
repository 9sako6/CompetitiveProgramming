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

void main_sub(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) { cin >> a[i][j]; }
    }
    int ans = 0;
    rep(k1, m) {
        for (int k2 = k1 + 1; k2 < m; ++k2) {
            int s = 0;
            rep(i, n) { s += max(a[i][k1], a[i][k2]); }
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
    return;
}