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
void print(const std::vector<int>& v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> p(N);
    vector<int> match(N);
    rep(i, N) {
        cin >> p[i];
        if (p[i] == i + 1) match[i] = 1;
    }
    vector<int> cnt;
    int tmp = 0;
    rep(i, N - 1) {
        if (match[i]) {
            if (match[i + 1]) {
                tmp++;
            } else {
                tmp++;
                cnt.push_back(tmp);
                tmp = 0;
            }
        }
    }
    if(match[N-1]) tmp++;
    cnt.push_back(tmp);
    int ans = 0;
    for (auto& i : cnt) {
        if (i == 1) {
            ans++;
        } else if(i > 0) {
            if (i & 1) ans += (i+1)/2;
            else ans += i/2;
        }
    }
    cout << ans << endl;

    return 0;
}
