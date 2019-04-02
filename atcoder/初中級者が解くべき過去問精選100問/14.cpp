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

int color(const vector<int>& a) {
    int cnt = 1;
    for (int i = 1; i < (int)a.size(); ++i) {
        bool flag = true;
        for (int j = 0; j < i; ++j) {
            if (a[i] <= a[j]) flag = false;
        }
        if (flag) cnt++;
    }
    return cnt;
}
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T& first, const A&... rest) {
    cout << sizeof...(rest) << endl;
    std::cout << first;
    if (sizeof...(rest)) std::cout << " ";
    print(rest...);
}
template <typename... A>
void print(const A&... rest) {
    print(rest...);
}
template <typename A>
void print(const std::vector<A>& v) {
    std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
    std::cout << std::endl;
}
void main_sub(void) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }
    if (n == k) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] <= a[i - 1]) {
                ans += (a[i - 1] - a[i] + 1);
                a[i] = a[i - 1] + 1;
            }
        }
        cout << ans << endl;
    } else {
        int ans = INF;
        rep(bit, (1 << n)) {
            vector<int> b = a;
            // 1が立ってる場所の建物が見える様に調整する
            int cost = 0;
            int mx = -1;
            rep(i, n) {
                if (bit & (1 << (n - 1 - i))) {
                    if (b[i] <= mx) {
                        cost += (mx + 1 - b[i]);
                        mx++;
                        b[i] = mx;
                    }
                }
                if (b[i] > mx) mx = b[i];
            }
            if (color(b) >= k) {
                ans = min(ans, cost);
                // cout << (bitset<5>(bit)) << endl;
                // print(b);
            }
        }
        cout << ans << endl;
    }

    return;
}