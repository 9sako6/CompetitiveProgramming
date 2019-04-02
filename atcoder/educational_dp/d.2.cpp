#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll dp[110][100010];
int main() {
    // O(NW)
    int N,W;
    scanf("%d%d", &N, &W);
    int w[N],v[N];
    rep(i, N) cin >> w[i] >> v[i];
    rep(i, N) rep(j, W+1){
        if(w[i] > j) dp[i+1][j] = dp[i][j];
        else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
    }
    cout << dp[N][W] << endl;
    return 0;
}