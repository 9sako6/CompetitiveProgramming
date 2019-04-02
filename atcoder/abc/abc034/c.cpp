#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = int64_t;

constexpr int INF = (1 << 30);
constexpr ll INFL = (1LL << 62);
constexpr ll MOD = 1000000007;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

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

int main() {
    cout << std::fixed << std::setprecision(10);
    int w, h;
    cin >> w >> h;
    w--;
    h--;
    Comb c(1'000'100, 1'000'000'007);
    cout << c.nCk(w + h, w) << endl;
    return 0;
}
