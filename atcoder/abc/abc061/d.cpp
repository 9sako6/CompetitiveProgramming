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

template<typename T>
struct edge {
    int from, to;
    T cost;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<edge<ll> > g(M);
    vector<ll> dist(N);
    fill(all(dist), INFL);
    rep(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        c = (ll)(-c);
        g[i] = {a, b, c};
    }
    dist[0] = 0;
    rep(j, N-1){
        rep(i, M){
            edge<ll> e = g[i];
            if(dist[e.from] != INFL && dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }
    vector<bool> negative(N);
    fill(all(negative), false);
    ll ans = dist[N-1];
    rep(j, N){
        rep(i, M){
            edge<ll> e = g[i];
            if(dist[e.from] != INFL && dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]){
                negative[e.to] = true;
            }
        }
    }
    if(negative[N-1]) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}