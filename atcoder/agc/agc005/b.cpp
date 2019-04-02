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
void print() { std::cout << std::endl; }
template <typename T, typename... A> void print(const T& first, const A&... rest) { cout << sizeof...(rest) << endl; std::cout << first; if (sizeof...(rest)) std::cout << " "; print(rest...); }
template <typename... A> void print(const A&... rest) { print(rest...); }
template <typename A> void print(const std::vector<A>& v) { std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; }); std::cout << std::endl; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) --a[i];
    vector<int> idx(n);
    rep(i, n) idx[a[i]] = i;
    ll ans = 0;
    set<int> s{-1, n};
    for (int x = 0; x < n; ++x) {
        int i = idx[x];
        auto itr = s.lower_bound(i);
        --itr;
        ll l = *itr;
        ++itr;
        ll r = *itr;
        ans += (i - l) * (x + 1) * (r - i);
        s.insert(i);
    }
    cout << ans << endl;

    return 0;
}
