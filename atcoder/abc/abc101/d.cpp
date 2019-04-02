#include <algorithm>
#include <cassert>
#include <climits>
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
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T& a, T b) {
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K;
    cin >> K;
    vector<ll> res;
    ll base = 1;
    auto s = [](ll n) -> ll {
        ll res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    };
    auto f = [&s](ll n) -> double { return (double)(n) / s(n); };

    for (int i = 0; i < 15; ++i) {
        for (int j = 1; j < 150; ++j) {
            res.push_back(base * (j + 1) - 1);
        }
        base *= 10;
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (ll i = 0; i < (ll)res.size(); i++) {
        for (ll j = i + 1; j < (ll)res.size(); j++) {
            if (f(res[i]) > f(res[j])) {
                res.erase(res.begin() + i--);
                break;
            }
        }
    }
    rep(i, K) { cout << res[i] << endl; }

    return 0;
}