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
#include <iomanip>
#include <numeric>
#include <complex>

using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const int INF = (1<<30);
const ll INFL = (1LL<<62);
const ll MOD = 1000000007;
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> ll mod_pow(ll a, ll n, T mod) { mod=(ll)mod; ll res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }

int dp[101010][2];

int main() {
    string s;
    cin >> s;
    dp[0][0] = 1;
    int N = s.size();
    rep(i, N){
        { // (a+b)[i] = 0
            if(s[i] == '0'){
                dp[i+1][0] = dp[i][0];
                dp[i+1][1] = dp[i][1];
            } else {
                dp[i+1][1] = (dp[i][0]+dp[i][1]) % MOD;
            }
        }
        { // (a+b)[i] = 1
            if(s[i] == '0'){
                (dp[i+1][1] += dp[i][1]*2 % MOD) %= MOD;
            } else {
                (dp[i+1][0] += dp[i][0]*2 % MOD) %= MOD;
                (dp[i+1][1] += dp[i][1]*2 % MOD) %= MOD; 
            }
        }
    }
    int ans = (dp[N][0] + dp[N][1]) % MOD;
    cout << ans << endl;
    return 0;
}