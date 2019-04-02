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
void print(const std::vector<int>& v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
void main_sub(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> x(n);
    vector<int> y(n);

    rep(i, n) {
        int xi, yi;
        cin >> xi >> yi;
        x[i] = xi;
        y[i] = yi;
        v[i] = i;
    }
    long double ans = 0;
    int cnt = 0;
    do {
        long double d = 0;
        rep(i, n - 1) {
            d += pow(pow(x[v[i]] - x[v[i + 1]], 2.0) +
                         pow(y[v[i]] - y[v[i + 1]], 2.0),
                     0.50);
        }
        ans += d;
        ++cnt;
    } while (next_permutation(all(v)));
    cout << fixed << setprecision(12);
    cout << ans / cnt << endl;
    return;
}