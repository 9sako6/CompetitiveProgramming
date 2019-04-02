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
    vector<int> a;
    int q;
    cin >> q;
    rep(i, q){
        int n;
        cin >> n;
        switch (n)
        {
        case 0:
            int x;
            cin >> x;
            a.push_back(x);
            break;
        case 1:
            int p;
            cin >> p;
            cout << a[p] << endl;
            break;
        default:
            a.pop_back();
            break;
        }
    }

    return 0;
}