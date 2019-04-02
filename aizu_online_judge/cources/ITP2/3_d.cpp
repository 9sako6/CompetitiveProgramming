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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    int t = min(n, m);
    rep(i, t){
        if(a[i] < b[i]){
            cout << 1 << endl;
            return 0;
        }else if (a[i] > b[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    if(n < m) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}