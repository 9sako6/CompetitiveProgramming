#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
mint dp[2][2005][2005];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n+1), t(m+1);
    rep(i, n) scanf("%d", &s[i]);
    rep(i, m) scanf("%d", &t[i]);
    dp[0][0][0] = 1;
    rep(i, n+1)rep(j, m+1){
        dp[0][i+1][j] += dp[0][i][j];
        dp[1][i][j] += dp[0][i][j];
        dp[1][i][j+1] += dp[1][i][j];
        if(s[i]==t[j]){
            dp[0][i+1][j+1] += dp[1][i][j];
        }
    }
    mint ans = dp[1][n][m];
    cout << ans.x << endl;
    return 0;
}