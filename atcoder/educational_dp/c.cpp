#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int> > abc(N+1, vector<int>(3));
    rep(i, N) scanf("%d%d%d", &abc[i][0], &abc[i][1], &abc[i][2]);
    int dp[N+1][3] = {};
    rep(i, N){
        dp[i+1][0] = max(dp[i][1]+abc[i][0], dp[i][2]+abc[i][0]);
        dp[i+1][1] = max(dp[i][0]+abc[i][1], dp[i][2]+abc[i][1]);
        dp[i+1][2] = max(dp[i][0]+abc[i][2], dp[i][1]+abc[i][2]);
    }
    int ans = max(dp[N][0], max(dp[N][1], dp[N][2]));
    printf("%d\n", ans);
    return 0;
}