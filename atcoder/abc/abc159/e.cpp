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

int hrange_cnt(int i, int ue, int shita, const vector<string>& s) {
    int ans = 0;
    // [ue, shita)
    for (int j = ue; j < shita; ++j) {
        ans += s[j][i] - '0';
    }
    return ans;
}
void main_sub(void) {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans = INFL;
    rep(bit, 1 << (h - 1)) {
        int cnt = __builtin_popcount(bit);
        vector<int> t;
        rep(i, h - 1) {
            if (bit & (1 << i)) t.push_back(i + 1);
        }
        rep(i, w) {
            
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return;
}