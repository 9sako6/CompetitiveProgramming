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
    int n;
    cin >> n;
    vector<int> l(2 * n);
    rep(i, 2 * n) { cin >> l[i]; }
    sort(all(l));
    ll ans = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        ans += l[i];
    }
    cout << ans << endl;
    return 0;
}
