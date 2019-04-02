#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N; cin >> N;
    long long h[100010];
    for(int i = 0; i < N; i++) {
       cin >> h[i];
    }
    long long dp[100010];
    for(int i = 0; i < N+10; i++) {
        dp[i] = INF;
    }
    dp[0]=0;
    for(int i = 1; i < N; i++) {
        dp[i] = min(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        if(i> 1) dp[i]=min(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[N-1] << endl;
}