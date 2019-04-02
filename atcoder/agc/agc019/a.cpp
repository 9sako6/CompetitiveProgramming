#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int Q,H,S,D,N;
    cin >> Q >> H >> S >> D;
    cin >> N;
    N *= 4;
    double cost[4] = {(double)Q*4, (double)H*2, (double)S/2, (double)D/4};
    sort(cost, cost+4);
    rep(i, 4) cout << cost[i] << endl;
    return 0;
}