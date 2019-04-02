#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    // 解の範囲(lb, ub]
    ll lb = -1, ub = 1e9;
    while (ub - lb > 1) {
        ll t = (lb + ub) / 2;
        ll cnt = 0;
        rep(i, n) {
            if (h[i] > t * b) {
                cnt += (ll)(ceil((double)(h[i] - t * b) / (a - b)));
            }
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