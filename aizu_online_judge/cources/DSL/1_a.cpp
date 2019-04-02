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

struct UnionFind{
    vector<int> data;
    UnionFind() {}
    UnionFind(int size) : data(size, -1) {}
    int find(int k){
        if(data[k] < 0) return k;
        return (data[k] = find(data[k]));
    }
    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    int size(int k){
        return (-data[find(k)]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};


int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf{n};
    rep(i, q){
        int com, x, y;
        cin >> com >> x >> y;
        if(com==0) uf.unite(x, y);
        else cout << (uf.same(x, y) ? 1 : 0) << endl;
    }

    return 0;
}