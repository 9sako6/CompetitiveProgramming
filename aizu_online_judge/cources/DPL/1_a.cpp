#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_map>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30);
const ll INFL = (1LL<<62);
const int MOD = 1000000007;
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> ll mod_pow(ll a, ll n, T mod) { mod=(ll)mod; ll res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }

int dp[22][505050];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for(auto &ci : c) cin >> ci;
    fill(dp[0], dp[0]+505049, INF);
    dp[0][0]=0;
    rep(i, m){
        rep(j, n+1){
            if(j >= c[i]) dp[i+1][j] = min(dp[i][j], dp[i+1][j-c[i]]+1);
            else dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}