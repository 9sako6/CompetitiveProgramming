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

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> Q[n];
    rep(i, m){
        int q, t, x;
        cin >> q;
        switch (q)
        {
        case 0:
            cin >> t >> x;
            Q[t].push(x);
            break;
        case 1:
            cin >> t;
            if(!Q[t].empty()) cout << Q[t].top() << endl;
            break;
        default:
            cin >> t;
            if(!Q[t].empty()) Q[t].pop();
            break;
        }
    }


    return 0;
}