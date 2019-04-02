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
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template<typename T>
struct edge {
    int to;
    T cost;
};

using P = pair<int, int>;

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<edge<int> > G[V];
    int d[V];
    
    rep(i, E){
        int s,t,c;
        cin >> s >> t >> c;
        G[s].push_back({t,c});
        // G[t].push_back({s,c});
    }
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[r] = 0;
    que.push(P(0, r)); // 最短距離、頂点番号
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(auto &e : G[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    for(const auto &c : d){
        if(c == INF) cout << "INF" << endl;
        else cout << c << endl;
    }
    return 0;
}