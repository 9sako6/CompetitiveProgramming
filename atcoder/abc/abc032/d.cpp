#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    ll N,W; cin >> N>>W;
    ll v[N], w[N];
    ll dp[N+1][W+1] = {};
    rep(i, N) cin >> v[i] >> w[i];
    rep(i, N) {
        rep(j, W+1){
            if (j < w[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}