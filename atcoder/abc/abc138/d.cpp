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
#include <cassert>
#include <climits>

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
void print() { std::cout << std::endl; }
template <typename T, typename... A> void print(const T& first, const A&... rest) { cout << sizeof...(rest) << endl; std::cout << first; if (sizeof...(rest)) std::cout << " "; print(rest...); }
template <typename... A> void print(const A&... rest) { print(rest...); }
template <typename A> void print(const std::vector<A>& v) { std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; }); std::cout << std::endl; }

vector<vector<int>> to(200005);
vector<int> ans;
void dfs(int v, int p = -1){
    for(int u : to[v]){
        if(u == p) continue;
        ans[u] += ans[v];
        dfs(u, v);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    scanf("%d %d", &n, &q);
    rep(i, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(n);
    rep(i, q){
        int p, x;
        scanf("%d %d", &p, &x);
        --p;
        ans[p] += x;
    }
    dfs(0);
    rep(i, n){
        printf("%d\n", ans[i]);
    }
    return 0;
}