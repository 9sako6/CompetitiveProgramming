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
    const int N = []() -> int {
        int t;
        cin >> t;
        return t;
    }();
    vector<int> t(N);
    vector<double> v(N);
    rep(i, N) cin >> t[i];
    rep(i, N) cin >> v[i];
    const int T = [&t]() -> int {
        int tmp = 0;
        for (auto& ti : t) tmp += ti;
        return tmp;
    }();
    vector<double> maxv(T * 2 + 1, (double)INF);
    int nowT = 0;
    rep(i, N) {
        rep(ti, t[i]) {
            int t1 = nowT + ti * 2;
            int t2 = nowT + ti * 2 + 1;
            maxv[t1] = min(maxv[t1], v[i]);
            maxv[t2] = min(maxv[t2], v[i]);
        }
        nowT += t[i] * 2;
        maxv[nowT] = min(maxv[nowT], v[i]);
    }
    maxv[0] = maxv[2 * T] = 0;
    rep(ti, 2 * T) { maxv[ti + 1] = min(maxv[ti + 1], maxv[ti] + 0.5); }
    for (int ti = 2 * T - 1; ti >= 0; ti--) {
        maxv[ti] = min(maxv[ti], maxv[ti + 1] + 0.5);
    }
    double ans = 0.0;
    rep(i, 2 * T + 1) { ans += (maxv[i] + maxv[i + 1]) * 0.5 / 2.0; }
    printf("%.6f\n", ans);

    return 0;
}