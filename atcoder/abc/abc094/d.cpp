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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &ai : a) cin >> ai;
    sort(all(a));
    int ans = 0;
    int max = a[n-1];
    int diff = INF;
    rep(i, n){
        if(max == a[i]) continue;
        int d = abs(max/2 - a[i]);
        if(d < diff) diff = d, ans = i;
    }
    sort(all(a), greater<int>());
    diff = INF;
    rep(i, n){
        if(max == a[i]) continue;
        int d = abs(max/2 - a[i]);
        if(d < diff) diff = d, ans = i;
    }
    printf("%d %d\n", max, a[ans]);

    return 0;
}
