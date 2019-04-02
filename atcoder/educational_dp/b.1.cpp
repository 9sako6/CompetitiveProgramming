#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main() {
    int N, K;
    cin >> N >> K;
    int h[N];
    rep(i, N) cin >> h[i];
    int dp[N+K+100];
    rep(i, N+K+100) dp[i] = INF;
    dp[0] = 0;
    rep(i, N){
        for(int j = 1; j <= K; j++){
            if (i+j < N) chmin(dp[i+j], dp[i]+abs(h[i]-h[i+j])); 
        }
    }
    cout << dp[N-1] << endl;

    return 0;
}
