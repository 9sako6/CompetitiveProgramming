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
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> q(n);
    rep(i, n) cin >> q[i];
    vector<int> v(n);
    rep(i, n) v[i] = i + 1;
    int a = -1;
    int b = -1;
    int cnt = 0;
    do {
        bool p_flag = true;
        bool q_flag = true;
        rep(i, n) {
            if (v[i] != p[i]) p_flag = false;
            if (v[i] != q[i]) q_flag = false;
        }
        if (p_flag) a = cnt;
        if (q_flag) b = cnt;
        cnt++;
    } while (next_permutation(all(v)));
    cout << abs(a - b) << endl;
    return;
}