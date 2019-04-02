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
    vector<int> s(h, 0);
    rep(i, h) {
        int d = pow(2, w - 1);
        rep(j, w) {
            int tmp;
            cin >> tmp;
            s[i] += tmp * d;
            d /= 2;
        }
    }
    rep(i, h) { cout << s[i] << endl; }
    int ans = 0;
    rep(bit, (1 << h)) {
        // vector<int> t(h);
        bool t[10][10001]{};
        rep(i, h) {
            rep(j, w) {
                if (bit & (1 << i)) {
                    t[i][w - j  -1] = !(s[i] & (1 << j));
                } else {
                    t[i][w - j - 1] = (s[i] & (1 << j));
                }
            }
        }
        int sum = 0;
        rep(j, w) {
            int cnt = 0;
            rep(i, h) {
                if (t[i][j]) cnt++;
            }
            sum += max(h - cnt, cnt);
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return;
}