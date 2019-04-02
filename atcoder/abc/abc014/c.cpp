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
const int MAX = 1000100;
int enogu[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        enogu[a]++;
        enogu[b + 1]--;
    }
    vector<int> sum(MAX, 0);
    rep(i, MAX) {
        if (i == 0) {
            sum[0] = enogu[0];
        } else {
            sum[i] = enogu[i] + sum[i - 1];
        }
    }
    cout << *max_element(all(sum)) << endl;

    return 0;
}