#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char* argv[]) {
    cout << std::fixed << std::setprecision(10);
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
    int K = -1;

    for (int i = 1; i <= n; ++i) {
        if (i * (i + 1) / 2 == n) {
            K = i;
            break;
        }
    }
    if (K == -1) {
        puts("No");
    } else {
        puts("Yes");
        cout << K + 1 << endl;

        vector<vector<int> > res(K + 1, vector<int>());
        int sum = 1;
        for (int k = K; k >= 1; --k) {
            for (int i = 0; i < k; ++i) {
                res[K - k].push_back(sum + i);
                res[K - k + i + 1].push_back(sum + i);
            }
            sum += k;
        }

        rep(i, K + 1) {
            cout << res[i].size();
            rep(j, res[i].size()) { cout << " " << res[i][j]; }
            cout << endl;
        }
    }

    return;
}