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

template <class T>
i64 mod_pow(i64 a, i64 n, T mod) {
    mod = (i64)mod;
    i64 res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}

void main_sub(void) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> t_mod(n + 1, 0);
    int i = n - 1;
    while (i >= 0) {
        t_mod[i] =
            (t_mod[i + 1] + (s[i] - '0') * mod_pow(10, n - i, 2019)) % 2019;
        --i;
    }
    unordered_map<int, int> cnt;
    for (auto t : t_mod) {
        cnt[t]++;
    }
    int ans = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        ans += it->second * (it->second - 1) / 2;
    }
    cout << ans << endl;
    return;
}
