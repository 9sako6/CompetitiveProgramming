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
    vector<vector<int>> r(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        r[x].push_back(y);
        r[y].push_back(x);
    }
    int ans = 0;
    rep(bit, (1 << n)) {
        vector<int> cands;
        rep(i, n) {
            if (bit & (1 << i)) cands.push_back(i);
        }
        int c_size = cands.size();
        int ok = true;
        rep(i, c_size) {
            for (int j = i + 1; j < c_size; ++j) {
                bool j_in_ri = false;
                for (auto& x : r[cands[i]]) {
                    if (x == cands[j]) j_in_ri = true;
                }
                if (!j_in_ri) ok = false;
            }
        }
        if (ok) ans = max(ans, (i64)__builtin_popcount(bit));
    }
    cout << ans << endl;
    return;
}