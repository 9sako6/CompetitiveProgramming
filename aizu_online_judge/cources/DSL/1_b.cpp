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
const ll INFL = (1L<<62);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template<typename T>
struct WeightedUnionFind {
    vector<int> data;
    vector<T> ws;
    
    WeightedUnionFind() {}
    
    WeightedUnionFind(int size) : data(size, -1), ws(size) {}

    int find(int k) {
        if(data[k] < 0) return k;
        auto par = find(data[k]);
        ws[k] += ws[data[k]];
        return data[k] = par;
    }

    T weight(int k) {
        find(k);
        return ws[k];
    }

    bool unite(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        x = find(x); y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) {
            swap(x, y);
            w *= -1;
        }
        data[x] += data[y];
        data[y] = x;
        ws[y] = w;
        return true;
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    WeightedUnionFind<int> uf(N);
    while(M--){
        int a, b, c, d;
        cin >> a >> b >> c;
        if(a==0){
            cin >> d;
            uf.unite(b, c, d);
        }else {
            if(uf.find(b) == uf.find(c)) {
                cout << uf.diff(b, c) << endl;
            }else{
                cout << "?" << endl;
            }
        }
    }

    return 0;
}