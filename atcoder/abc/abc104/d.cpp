#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    ll dp[100010][4] = {};
    for(int i=N; i >= 0; --i){
        for(int j=3; j>=0; --j){
            if(i==N){
                dp[i][j] = (j == 3 ? 1: 0);
            }else{
                dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3LL : 1LL);
                if(j < 3 && (s[i] == '?' || s[i] == "ABC"[j])){
                    dp[i][j] += dp[i+1][j+1];
                }
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}