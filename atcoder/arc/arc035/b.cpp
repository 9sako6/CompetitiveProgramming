#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const i64 MAX = 10010;
    i64 n{0};
    cin >> n;
    vector<i64> t(n);
    map<i64, i64> cnt;
    rep(i, n) {
        cin >> t.at(i);
        cnt[t.at(i)]++;
    }
    sort(all(t));
    i64 fact[MAX];
    fact[0] = 1;
    for (i64 i = 1; i < MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    i64 sum = 0;
    i64 tmp = 0;
    rep(i, n) {
        tmp += t.at(i);
        sum += tmp;
    }
    i64 ans = 1;
    for (const auto& c : cnt) {
        (ans *= fact[c.second]) %= MOD;
    }
    cout << sum << endl;
    cout << ans << endl;

    return 0;
}