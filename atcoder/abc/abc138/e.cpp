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

bool isOk(const string& s, const string& t) {
    unordered_map<char, bool> str1;
    for (auto& c : s) {
        str1[c] = true;
    }
    for (auto& c : t) {
        if (!str1[c]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if (!isOk(s, t)) {
        cout << -1 << endl;
        return 0;
    }
    const ll N = s.size();
    unordered_map<char, vector<int>> index;
    rep(i, N) { index[s[i]].push_back(i); }
    ll l = 0LL;
    int id = index[t[0]].front();  // 1文字目
    const ll M = t.size();
    for (int i = 1; i < M; i++) {
        int j = upper_bound(all(index[t[i]]), id) - index[t[i]].begin();
        if (j == (int)index[t[i]].size()) {
            l++;
            id = index[t[i]][0];
        } else {
            id = index[t[i]][j];
        }
    }
    cout << (ll)(id + 1) + l * (ll)N << endl;

    return 0;
}
