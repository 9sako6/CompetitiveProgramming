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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> h(N);
    rep(i, N) { cin >> h[i]; }
    auto count = [&A, &B](ll h, ll t) {
        return (ll)ceil(double(h - B * t) / (A - B));
    };
    // 解の存在範囲(lb, ub]
    ll lb = -1, ub = (ll)(*max_element(all(h)));
    while (ub - lb > 1) {
        ll t = (lb + ub) / 2;
        ll cnt = 0;
        for (auto &hi : h) {
            if (hi > (t * B)) {
                cnt += count(hi, t);
            }
            if (cnt > t) break;
        }
        if (cnt <= t) {
            ub = t;
        } else {
            lb = t;
        }
    }
    cout << ub << endl;
    return 0;
}