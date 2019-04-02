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
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    sort(all(s));
    int q;
    cin >> q;
    int cnt = 0;
    rep(i, q) {
        int t;
        cin >> t;
        if (binary_search(all(s), t)) ++cnt;
    }
    cout << cnt << endl;

    return;
}