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
    int q;
    list<int> L;
    list<int>::iterator it=L.end();
    cin >> q;
    rep(i, q){
        int n;
        cin >> n;
        switch(n){
        case 0:
            int x;
            cin >> x;
            it=L.insert(it, x);
            break;
        case 1:
            int d;
            cin >> d;
            if(d > 0) rep(i, d) it++;
            else rep(i, -d) it--;
            break;
        case 2:
            it=L.erase(it);
        }
    }
    for(const auto &a : L) cout << a << endl;

    return 0;
}