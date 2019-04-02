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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    vector<int> p(m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int sj;
            cin >> sj;
            s[i].push_back(sj);
        }
    }
    rep(i, m) { cin >> p[i]; }
    int ans = 0;
    rep(bit, (1LL << n)) {
        int all_on = true;
        rep(i, m) {
            int cnt = 0;
            for (auto& sij : s[i]) {
                if (bit & (1 << (sij - 1))) {
                    cnt++;
                }
            }
            if (cnt % 2 != p[i]) all_on = false;
        }
        if (all_on) ans++;
    }
    cout << ans << endl;
    return;
}
