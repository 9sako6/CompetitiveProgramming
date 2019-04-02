#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    i64 n, t;
    cin >> n >> t;
    vector<i64> a(n);
    vector<i64> b(n);
    rep(i, n) { cin >> a[i] >> b[i]; }

    i64 dp1[n + 2][t] = {};
    i64 dp2[n + 2][t] = {};

    // i, j: 1-indexed
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < t; ++j) {
            chmax(dp1[i][j], dp1[i - 1][j]);
            if (a[i - 1] <= j) {
                chmax(dp1[i][j], dp1[i - 1][j - a[i - 1]] + b[i - 1]);
            }
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j < t; ++j) {
            chmax(dp2[i][j], dp2[i + 1][j]);
            if (a[i - 1] <= j) {
                chmax(dp2[i][j], dp2[i + 1][j - a[i - 1]] + b[i - 1]);
            }
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < t; ++j) {
            chmax(ans, dp1[i - 1][j] + dp2[i + 1][t - j - 1] + b[i - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}