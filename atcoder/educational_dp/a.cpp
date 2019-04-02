#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N;
    cin >> N;
    int h[N];
    rep(i, N) cin >> h[i];
    int dp[100100];
    rep(i, 100100) dp[i] = INF;
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    rep(i, N){
        chmin(dp[i+1], dp[i] + abs(h[i]-h[i+1]));
        chmin(dp[i+2], dp[i] + abs(h[i]-h[i+2]));
    }
    cout << dp[N-1] << endl;
    return 0;
}