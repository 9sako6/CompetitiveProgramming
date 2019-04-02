#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (1LL<<60);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll dp[110][100100];
int main() {
    int N;
    ll W;
    cin >> N >> W;
    ll w[N];
    int v[N];
    rep(i, N) cin >> w[i] >> v[i];
    for(int j=1; j < 100100; ++j) dp[0][j] = INF;
    rep(i, N) rep(j, 100100){
        if(j < v[i]) dp[i+1][j] = dp[i][j];
        else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
    }
    ll ans = 0;
    rep(j, 100100){
        if(dp[N][j] <= W) ans = (ll)j;
    }
    cout << ans << endl;
    return 0;
}