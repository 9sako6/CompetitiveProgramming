#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const ll INFL = (1LL << 62);
const ll MOD = 1000000007;
template <class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
template <class T>
ll mod_pow(ll a, ll n, T mod) {
    mod = (ll)mod;
    ll res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}
template <int mod>
struct ModInt {
    using ll = long long;
    ll x;
    ModInt() : x(0) {}
    ModInt(int y) : x(y >= 0 ? ll(y % mod) : (ll)((mod - (-y) % mod))) {}
    ModInt(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
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
        ll t;
        is >> t;
        rhs = ModInt<mod>(t);
        return (is);
    }

   private:
    ModInt inverse() const {
        ll a = x, u = 1LL, v = 0LL, t, b = (ll)mod;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
};
using mint = ModInt<MOD>;

int F[110][10];
int P[110][11];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    rep(i, N) rep(j, 10) cin >> F[i][j];
    rep(i, N) rep(j, 11) cin >> P[i][j];
    ll ans = -INFL;
    // 営業パターンは2^10
    // 1回も営業しないのは弾く
    for (int bit = 0; bit < (2 << 10); bit++) {
        if (bit == 0) continue;
        vector<int> joi;
        for (int i = 0; i <= 9; ++i) {
            if (bit & (1 << i)) {
                joi.push_back(i);
            }
        }
        if(joi.size()==0) continue;
        ll score = 0;
        rep(i, N) {
            int cnt = 0;
            for (auto &j : joi) {
                if (F[i][j]) cnt++;
            }
            score += (ll)P[i][cnt];
        }
        ans = max(ans, score);
    }
    cout << ans << endl;

    return 0;
}