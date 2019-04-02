#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

typedef struct {
    int to;
    ll cost;
} edge;

int main() {
    int N;
    scanf("%d", &N);
    vector<edge> tree[N];
    rep(i, N-1){
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    int Q, K;
    scanf("%d%d", &Q, &K);
    K--;
    stack<edge> s;
    s.push({K, 0});
    ll depth[N];
    rep(i, N) depth[i] = -1;
    while(!s.empty()){
        edge from = s.top();
        s.pop();
        depth[from.to] = (ll)from.cost;
        for(edge to : tree[from.to]){
            if(depth[to.to] == -1) s.push({to.to, to.cost + from.cost});
        }
    }
    rep(i, Q){
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        printf("%lld\n", depth[x] + depth[y]);
    }

    return 0;
}
