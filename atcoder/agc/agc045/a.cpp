#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = int64_t;

constexpr int INF = (1 << 30);
constexpr ll INFL = (1LL << 62);
constexpr ll MOD = 1000000007;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    cout << std::fixed << std::setprecision(10);
    int t;
    cin >> t;
    vector<int> ans(t);
    rep(i, t) {
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];
        int s;
        cin >> s;
        int x = 0;
        vector<int> p0bit(18, 0);
        vector<int> p1bit(18, 0);
        rep(j, n) {
            rep(bit, 18) {
                if (a[j] & (1 << bit)) {
                    if (s & (1 << j)) {
                        // people 1
                        p1bit[bit]++;
                    } else {
                        // people 2
                        p0bit[bit]++;
                    }
                }
            }
        }
        int win1 = true;
        rep(j, 18) {
            if (p1bit[j] > p0bit[0]) {
                win1 = false;
            }
        }
        ans.push_back((win1 ? 1 : 0));
    }
    rep(i, t) { cout << ans[i] << endl; }
    return 0;
}
