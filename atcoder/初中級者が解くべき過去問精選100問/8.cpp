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
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int score(const vector<vector<int>>& p, int n_in, int n_out) {
    int n = p.size();
    int s = 0LL;
    rep(i, n) {
        s += abs(n_in - p[i][0]);
        s += abs(p[i][0] - p[i][1]);
        s += abs(p[i][1] - n_out);
    }
    return s;
}

void main_sub(void) {
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(2));
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    int ans = INFL;
    rep(i_in, n) {
        rep(i_out, n) {
            rep(i, 2) {
                rep(j, 2) {
                    int n_in = p[i_in][i];
                    int n_out = p[i_out][j];
                    ans = min(ans, score(p, n_in, n_out));
                    // cout << n_in << " " << n_out << endl;
                }
            }
        }
    }
    cout << ans << endl;

    return;
}