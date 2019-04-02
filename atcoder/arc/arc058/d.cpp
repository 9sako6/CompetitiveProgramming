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

struct ModCombination {
    vector<unsigned int> F;
    ModCombination(unsigned int n) : F(n+1, 1){
        for(unsigned int i=1; i <= n; i++){
            F[i] = 1LL * F[i-1] * i % MOD;
        }
    }
    unsigned int operator()(unsigned int a, unsigned int b){
        if(b > a) return 0;
        return 1LL * F[a] * mod_pow(F[b], MOD-2, MOD) % MOD * mod_pow(F[a-b], MOD-2, MOD) % MOD;
    }
};

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    ModCombination mc(H+W);
    int ans = 0;
    for(int i=B+1; i<=W; i++){
        ans += ((int64_t)mc(H-A+i-2, i-1) * mc(W-i+A-1, A-1)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}