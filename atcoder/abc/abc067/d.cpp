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

void dfs(const int start, vector<int> &dist, vector<vector<int>> &tree) {
    deque<pair<int, int>> s;
    s.push_back({start, 0});
    bool visited[tree.size()] = {};
    while (!s.empty()) {
        pair<int, int> p = s.back();
        s.pop_back();
        visited[p.first] = true;
        dist[p.first] = p.second;
        for (auto &node : tree[p.first]) {
            if (!visited[node]) {
                s.push_back({node, p.second + 1});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> dist_f(N, 0), dist_s(N, 0);
    vector<vector<int>> tree(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, dist_f, tree);
    dfs(N - 1, dist_s, tree);
    int cnt = 0;
    rep(i, N) {
        if (dist_f[i] > dist_s[i]) cnt++;
    }
    if (cnt >= N - cnt)
        cout << "Snuke" << endl;
    else
        cout << "Fennec" << endl;

    return 0;
}