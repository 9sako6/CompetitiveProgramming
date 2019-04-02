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

//
// O(N)で前処理をし、O(1)で二項係数(mod)を求める
//
// ref: http://drken1215.hatenablog.com/entry/2018/06/08/210000
// verify: https://atcoder.jp/contests/abc145/tasks/abc145_d
struct Comb {
    using i64 = int64_t;
    const i64 mod;
    std::vector<i64> fact;     // a!
    std::vector<i64> factinv;  // (a!)^-1
    std::vector<i64> inv;      // mod. p における 1,2,...,n の逆元
    Comb(int maximum, i64 m)
        : mod(m), fact(maximum, 0), factinv(maximum, 0), inv(maximum, 0) {
        // テーブルを作る前処理
        fact[0] = factinv[0] = 1;
        fact[1] = factinv[1] = 1;
        inv[1] = 1;
        for (i64 i = 2; i < maximum; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            factinv[i] = factinv[i - 1] * inv[i] % mod;
        }
    }
    i64 nCk(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fact[n] * (factinv[k] * factinv[n - k] % mod) % mod;
    }
};

void main_sub(void) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int ans{0};

    Comb c(1000000, MOD);
    rep(i, n) {
        int now = c.nCk(i, k - 1) % MOD;
        ans += (now * a[n - 1 - i]) % MOD;
        ans %= MOD;
        ans -= (now * a[i]) % MOD;
        ans %= MOD;
    }
    cout << -ans << endl;

    return;
}