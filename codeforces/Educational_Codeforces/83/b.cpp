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
    int t;
    cin >> t;
    rep(_, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) { cin >> a[i]; }
        sort(all(a), greater<int>());
        rep(i, n) { printf("%lld%c", a[i], i == n - 1 ? '\n' : ' '); }
    }
    return;
}