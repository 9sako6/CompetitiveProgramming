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
int a[30];
bool rec(int i, int s) {
    if (i == 0) {
        return s == 0;
    }
    return rec(i - 1, s) || rec(i - 1, s - a[i - 1]);
}

void main_sub(void) {
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    int q;
    cin >> q;
    rep(i, q) {
        int m;
        cin >> m;
        cout << (rec(n, m) ? "yes" : "no") << endl;
    }

    return;
}
