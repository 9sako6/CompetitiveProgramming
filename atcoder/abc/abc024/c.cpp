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
int n, d, k;
int L[10010], R[10010];
int S[110], T[110];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> d >> k;
    rep(i, d) cin >> L[i] >> R[i];
    rep(i, k) cin >> S[i] >> T[i];
    rep(i, k) {
        int now = S[i];
        rep(j, d) {
            if (L[j] <= now && now <= R[j]) {
                if (now <= T[i]) {
                    now = R[j];
                    if (now >= T[i]) {
                        cout << j + 1 << endl;
                        break;
                    }
                } else {
                    now = L[j];
                    if (now <= T[i]) {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}