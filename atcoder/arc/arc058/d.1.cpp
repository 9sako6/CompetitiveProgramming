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
  ModCombination(unsigned int n) : n(n), F(n + 1, 1), I(n + 1, 1) {
    for (unsigned int i = 1; i <= n; ++i) F[i] = 1ll * i * F[i - 1] % MOD;
    for (int64_t i = MOD - 2, j = F[n]; i; i >>= 1) {
      if (i & 1) I[n] = I[n] * j % MOD;
      j = j * j % MOD;
    }
    for (int i = n - 1; i; --i) I[i] = I[i + 1] * (i + 1ll) % MOD;
  }

  unsigned int n;
  vector<int> F, I;

  int operator()(int p, int k) {
    if (k < 0 || k > p) return 0;
    return 1ll * F[p] * I[k] % MOD * I[p - k] % MOD;
  }
};


int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    ModCombination mC(H+W);
    int ans = 0;
    for(int i=B+1; i<=W; i++){
        ans += ((int64_t)mC(H-A+i-2, i-1) * mC(W-i+A-1, A-1)) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}