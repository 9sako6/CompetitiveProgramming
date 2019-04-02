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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        rep(i, n) { cin >> v[i]; }
        bool invalid_flag = false;
        unordered_map<int, bool> cnt;
        rep(i, n) {
            int tmp = v[i];
            int j = 0;
            while (tmp > 0) {
                if (!(tmp % k == 0 || tmp % k == 1)) {
                    invalid_flag = true;
                    break;
                }
                if (tmp % k == 1) {
                    if (cnt[j])
                        invalid_flag = true;
                    else
                        cnt[j] = true;
                }
                tmp /= k;
                ++j;
            }
        }

        if (invalid_flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return;
}