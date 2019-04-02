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
const int MOD = 1000000007;
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> ll mod_pow(ll a, ll n, T mod) { mod=(ll)mod; ll res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }

int D[33][33];
int c[550][550];
int sum[3][33];
int main() {
    int N, C;
    cin >> N >> C;
    rep(i, C) rep(j, C) scanf("%d", D[i] + j);
    rep(i, N) rep(j, N) scanf("%d", c[i] + j);

    rep(color, C){
        rep(i, N) rep(j, N){
            if((i+j+2) % 3 == 0) sum[0][color] += D[c[i][j]-1][color];
            if((i+j+2) % 3 == 1) sum[1][color] += D[c[i][j]-1][color];
            if((i+j+2) % 3 == 2) sum[2][color] += D[c[i][j]-1][color];
        }
    }
    int ans = INF;
    rep(c0, C){
        rep(c1, C){
            if(c0 == c1) continue;
            rep(c2, C){
                if(c1 == c2 || c0 == c2) continue;
                chmin(ans, sum[0][c0]+sum[1][c1]+sum[2][c2]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}