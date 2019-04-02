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
    int n,q;
    cin >> n >> q;
    vector<int> A[n];
    vector<string> ans;
    rep(i, q){
        int a,b,c;
        cin >> a;
        switch (a)
        {
        case 0:
            cin >> b >> c;
            A[b].push_back(c);
            break;
        case 1:{
            cin >> b;
            int N = A[b].size();
            string s;
            rep(i, N) s.append(to_string(A[b][i]) + " ");
            if(s.size() > 0)s.pop_back();
            ans.push_back(s);
            break;
        }
        case 2:
            cin >> b;
            A[b].clear();
            break;
        }
    }
    int N = ans.size();
    rep(i, N) cout << ans[i] << endl;
    return 0;
}