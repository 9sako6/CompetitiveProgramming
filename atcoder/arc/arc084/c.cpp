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
#define int ll
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


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    sort(all(A));
    sort(all(B));
    sort(all(C));
    vector<int> less(N), more(N);
    ll ans = 0;
    rep(i, N) {
        int j = C.end() - upper_bound(all(C), B[i]);
        int k = N - (A.end() - lower_bound(all(A), B[i]));
        ans += j*k;
    }
    cout << ans << endl;
    return 0;
}
