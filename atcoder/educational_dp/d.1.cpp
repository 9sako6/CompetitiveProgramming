#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll dp[110][100010];

int main() {
    int N, W;
    cin >> N >> W;
    ll w[N], v[N];
    rep(i, N) cin >> w[i] >> v[i];
    rep(i, N) {
        rep(j, W+1) {
            if(j >= w[i]) chmax(dp[i+1][j], dp[i][j-w[i]] + v[i]);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}