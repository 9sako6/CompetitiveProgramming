#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int MOD = 1000000007;
int dp[1010][1010];

int main() {
    int H,W;
    scanf("%d%d", &H, &W);
    string a[H];
    rep(i, H) cin >> a[i];
    for(int i=1; i < W; ++i){
        if(a[0][i] == '#') break;
        dp[0][i] = 1;
    }
    for(int i=1; i < H; ++i){
        if(a[i][0] == '#') break;
        dp[i][0] = 1;
    }
    for(int i=1; i < H; ++i){
        for(int j=1; j < W; ++j){
            if(a[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    printf("%d\n", dp[H-1][W-1]);
    return 0;
}