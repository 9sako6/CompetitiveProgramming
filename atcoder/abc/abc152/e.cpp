#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const i64 MOD = 1000000007;
template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
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
    i64 n;
    cin >> n;
    vector<i64> a(n);
    rep(i, n) { cin >> a[i]; }
    mint l = 1;
    rep(i, n) { l = lcm(l, a[i]); }
    mint ans = 0;
    rep(i, n) {
        ans += l / mint(a[i]);
        // ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
