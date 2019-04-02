#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int dp[3010][3010];
int main() {
    string s, t;
    cin >> s >> t;
    int N = (int)s.size();
    int M = (int)t.size();
    rep(i, N){
        rep(j, M){
            if(s[i] == t[j]){
                chmax(dp[i+1][j+1], dp[i][j] + 1);
            }else{
                chmax(dp[i+1][j+1], dp[i+1][j]);
                chmax(dp[i+1][j+1], dp[i][j+1]);
            }
        }
    }
    string ans = "";
    while (N > 0 && M > 0){
        if(dp[N][M] == dp[N-1][M]){
            --N;
        }else if(dp[N][M] == dp[N][M-1]){
            --M;
        }else{
            --N, --M;
            ans = s[N] + ans;
        }
    }
    cout << ans << endl;
    return 0;
}