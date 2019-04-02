#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

template <int mod>
struct ModInt {
    using i64 = int64_t;
    i64 x;
    ModInt() : x(0) {}
    ModInt(i64 y) : x(y >= 0 ? y % mod : ((mod + y) % mod)) {}
    ModInt &operator+=(const ModInt &rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &rhs) {
        if ((x += mod - rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &rhs) {
        x = x * rhs.x % mod;
        return *this;
    }
    ModInt &operator/=(const ModInt &rhs) {
        *this *= rhs.inverse();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
    ModInt operator==(const ModInt &rhs) const { return x == rhs.x; }
    ModInt operator!=(const ModInt &rhs) const { return x != rhs.x; }
    friend ostream &operator<<(ostream &os, const ModInt &rhs) {
        return os << rhs.x;
    }
    friend istream &operator>>(istream &is, ModInt &rhs) {
        i64 t;
        is >> t;
        rhs = ModInt<mod>(t);
        return (is);
    }

   private:
    ModInt inverse() const {
        i64 a = x, u = 1LL, v = 0LL, t, b = (i64)mod;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
};
using mint = ModInt<1000000007>;

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    i64 n, k;
    cin >> n >> k;

    if (k >= (n - 1)) {
        k = n - 1;
        vector<i64> fact(n + k + 1);
        fact[0] = 1;
        for (i64 i = 1; i <= n + k; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        i64 ans = fact[n + k];
        ans *= mod_pow(fact[k], MOD - 2, MOD);
        ans %= MOD;
        ans *= mod_pow(fact[n], MOD - 2, MOD);
        ans %= MOD;
        cout << ans << endl;
    } else {
        // 作れない組み合わせを引いていく
        i64 a = k;
        k = n - 1;
        vector<i64> fact(n + k + 1);
        fact[0] = 1;
        for (i64 i = 1; i <= n + k; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        i64 ans = fact[n + k];
        ans *= mod_pow(fact[k], MOD - 2, MOD);
        ans %= MOD;
        ans *= mod_pow(fact[n], MOD - 2, MOD);
        ans %= MOD;

        for (i64 i = 1; i <= n - a - 1; ++i) {
            // nCi
            i64 nci = fact[n];
            nci *= mod_pow(fact[i], MOD - 2, MOD);
            nci %= MOD;
            nci *= mod_pow(fact[n - i], MOD - 2, MOD);
            nci %= MOD;
            //
            i64 juhuku = fact[i + i - 1];
            juhuku *= mod_pow(fact[i], MOD - 2, MOD);
            juhuku %= MOD;
            juhuku *= mod_pow(fact[i - 1], MOD - 2, MOD);
            juhuku %= MOD;
            nci *= juhuku;
            nci %= MOD;
            ans -= nci;
            if (ans < 0) ans += MOD;
        }
        cout << ans << endl;
    }

    return 0;
}