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

vector<int> divs(int n) {
    vector<int> ans;
    int i = 1;
    while (n >= i * i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
        i++;
    }
    return ans;
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

int operate(int n, int k) {
    if (k == 1) return n;
    while (n >= k) {
        if (n % k == 0) {
            n /= k;
        } else {
            n %= k;
        }
    }
    return n;
}

void main_sub(void) {
    int n;
    cin >> n;
    int ans = 0;
    for (auto d : divs(n)) {
        if (operate(n, d) == 1) ++ans;
    }
    for (auto d : divs(n - 1)) {
        if (operate(n, d) == 1) ++ans;
    }
    cout << ans << endl;
    return;
}