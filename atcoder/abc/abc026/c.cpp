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
    int N;
    cin >> N;
    vector<vector<int>> tree(N + 1);
    vector<int> income(N + 1, 1);
    for (int i = 2; i <= N; i++) {
        int num;
        cin >> num;
        tree[num].push_back(i);
    }
    for (int i = N; i >= 1; i--) {
        if (tree[i].empty()) {
            continue;
        } else {
            int max_in = -INF, min_in = INF;
            for (auto& child_i : tree[i]) {
                if (income[child_i] > max_in) max_in = income[child_i];
                if (income[child_i] < min_in) min_in = income[child_i];
            }
            income[i] = max_in + min_in + 1;
        }
    }
    cout << income[1] << endl;

    return 0;
}