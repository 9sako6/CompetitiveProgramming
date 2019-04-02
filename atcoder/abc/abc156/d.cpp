#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
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

template <int mod>
struct ModInt {
    using i64 = int64_t;
    i64 x;
    ModInt() : x(0) {}
    ModInt(i64 y) : x(y >= 0 ? y % mod : ((mod - (-y) % mod) % mod)) {}
    constexpr ModInt &operator+=(const ModInt &rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        if ((x += mod - rhs.x) >= mod) x -= mod;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) {
        x = x * rhs.x % mod;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) {
        *this *= rhs.inverse();
        return *this;
    }
    constexpr ModInt operator-() const { return ModInt(-x); }
    constexpr ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
    constexpr ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
    constexpr ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
    constexpr ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
    constexpr ModInt operator==(const ModInt &rhs) const { return x == rhs.x; }
    constexpr ModInt operator!=(const ModInt &rhs) const { return x != rhs.x; }
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    i64 n, a, b;
    cin >> n >> a >> b;
    mint ans = (mod_pow(2, n, MOD) - 1) % MOD;
    mint nca = 1;
    rep(k, a) { nca *= (n - k); }
    rep(k, a) { nca /= (k + 1); }
    mint ncb = 1;
    rep(k, b) { ncb *= (n - k); }
    rep(k, b) { ncb /= (k + 1); }

    ans -= nca;
    ans -= ncb;

    cout << ans << endl;

    return 0;
}