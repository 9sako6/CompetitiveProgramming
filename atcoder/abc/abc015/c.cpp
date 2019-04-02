#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int N,K;
int T[10][10];
bool isBugged = false;
void dfs(int n, int x){
    if(n == N+1){
        if(x==0) isBugged = true;
        return;
    }
    rep(i, K) dfs(n+1, x^T[n+1][i]);
}
int main() {
    cin >> N >> K;
    rep(i, N)rep(j, K) cin >> T[i][j];
    string ans = "Nothing";
    rep(k, K){
        dfs(0, T[0][k]);
    }
    if(isBugged) ans = "Found";
    cout << ans << endl;
    return 0;
}
