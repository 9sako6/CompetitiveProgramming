#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll dp[100010][3]; // dp[i][j]: i日目までで、i日目でj番目を選んだ時のマキシマムザ幸福
int main() {
    int N;
    cin >> N;
    int abc[N][3];
    rep(i, N) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
    // ll dp[100010][3]; // dp[i][j]: i日目までで、i日目でj番目を選んだ時のマキシマムザ幸福
    // rep(i, 100010){
    //     rep(j, 3) dp[i][j] = 0;
    // }
    rep(i, N){
        rep(j, 3) {
            rep(k, 3){
                if (j==k) continue;
                chmax(dp[i+1][k], dp[i][j] + abc[i][k]);
            }
        }
    }
    ll ans = 0;
    rep(i, 3) chmax(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
}