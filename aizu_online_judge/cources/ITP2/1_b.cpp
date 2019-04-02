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
    cin >> q;
    deque<int> a;
    vector<int> ans;
    rep(i, q){
        int n, d, x, p;
        cin >> n;
        switch(n){
        case 0:
            cin >> d >> x;
            if(d==0)a.push_front(x);
            else a.push_back(x);
            break;
        case 1:
            cin >> p;
            ans.push_back(a[p]);
            break;
        default:
            cin >> d;
            if(d==0)a.pop_front();
            else a.pop_back();
            break;
        }
    }
    int N = ans.size();
    rep(i, N) cout << ans[i] << endl;
    return 0;
}