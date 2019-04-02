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
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T& first, const A&... rest) {
    cout << sizeof...(rest) << endl;
    std::cout << first;
    if (sizeof...(rest)) std::cout << " ";
    print(rest...);
}
template <typename... A>
void print(const A&... rest) {
    print(rest...);
}
template <typename A>
void print(const std::vector<A>& v) {
    std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
    std::cout << std::endl;
}

// https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
// 【問題概要】
// 長さnの文字列Sが与えられる。
// Sの部分文字列 (空文字含む) として考えられるものの個数を数え上げよ。
// ただし答えがとても大きくなることがあるので、個数を 1,000,000,007
// で割ったあまりを求めよ。 【制約】 1<=n<=10^5 Sに登場する文字は英小文字のみ
// (26 種類)

vector<vector<int>> calcNext(const string& s) {
    int n = (int)s.size();
    vector<vector<int>> res(n + 1, vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            res[i][j] = res[i + 1][j];
        }
        res[i][s[i] - 'a'] = i;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // dp[i]:= 文字列Sにおいて、i-1番目の文字(0-indexed)
    // は必ず使うものとして、Sのうち0からi-1番目の部分から得られる部分文字列の個数
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> next = calcNext(s);

    // DP
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    rep(i, n) {
        rep(j, 26) {
            if (next[i][j] >= n) continue;
            (dp[next[i][j] + 1] += dp[i]) %= MOD;
        }
    }
    ll ans = 0;
    rep(i, n + 1) { (ans += dp[i]) %= MOD; }
    cout << ans << endl;

    return 0;
}