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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (10 % p == 0) {
        int ans = 0;
        rep(i, n) {
            if ((s[i] - '0') % p == 0) {
                ans += i + 1;
            }
        }
        cout << ans << endl;
        return;
    }
    vector<int> d(n + 1, 0);
    int ten = 1;
    for (int i = n - 1; i >= 0; --i) {
        int a = (s[i] - '0') * ten % p;
        d[i] = (d[i + 1] + a) % p;
        ten *= 10;
        ten %= p;
    }
    vector<int> cnt(p);
    int ans = 0;
    for (int i = n; i >= 0; --i) {
        ans += cnt[d[i]];
        cnt[d[i]]++;
    }
    cout << ans << endl;
    return;
}