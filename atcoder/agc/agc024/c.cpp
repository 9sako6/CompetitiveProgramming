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

i64 mod_pow(i64 a, i64 n) {
    // mod = (i64)mod;
    i64 res = 1, p = a;
    while (n) {
        if (n & 1) res = res * p;
        p = p * p;
        n >>= 1;
    }
    return res;
}

void main_sub(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    if (a[0] != 0) {
        cout << -1 << endl;
        return;
    }
    rep(i, n - 1) {
        if (a[i + 1] - a[i] >= 2) {
            cout << -1 << endl;
            return;
        }
    }
    int ans = 0;
    vector<pair<int, int>> s;
    int prev = -1;
    int cnt = 1;
    rep(i, n) {
        if (prev == a[i]) {
            cnt++;
        } else {
            s.push_back({prev, cnt});
            cnt = 1;
            prev = a[i];
        }
        if (a[i] != 0) ans++;
    }
    s.push_back({prev, cnt});
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i].first == 0 || s[i].first == 1) {
            continue;
        } else {
            ans +=
                mod_pow((i64)2, (i64)(s[i].first - 2LL)) * (s[i].second - 1LL);
        }
    }
    cout << ans << endl;
    return;
}