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

void dump(const list<int> &list){
    bool isFirst = true;
    for(const auto &l : list){
        if(!isFirst) cout << " ";
        cout << l;
        isFirst = false;
    }
    cout << "\n";
}

int main() {
    int n,m;
    cin >> n >> m;
    list<int> L[n];
    int q, t, x;
    rep(i, m){
        cin >> q;
        switch (q)
        {
        case 0:
            cin >> t >> x;
            L[t].insert(L[t].end(), x);            
            break;
        case 1:
            cin >> t;
            dump(L[t]);
            break;
        default:
            cin >> t >> x;
            L[x].splice(L[x].end(), move(L[t]));
            L[t] = list<int>{};
            break;
        }
    }

    return 0;
}