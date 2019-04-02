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
void main_sub(void) {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    rep(i, n) {
        if (s[i] == 'x') {
            a[i] += 1;
            if (i + 1 < n) a[i + 1] -= 1;
        } else {
            if (i + 1 < n) a[i + 1] += 1;
            if (i + c + 1 < n) {
                a[i + c + 1] -= 1;
            }
        }
    }
    print(a);

    rep(i, n) {
        if (0 < i) a[i] += a[i - 1];
    }
    print(a);
    int l = 0;
    rep(i, n) {
        if (a[i] == 0) {
            l = i;
            break;
        }
    }
    if (l + 1 < n && s[l + 1] == 'o') {
        a[l] = 1;
    }
    print(a);

    return;
}