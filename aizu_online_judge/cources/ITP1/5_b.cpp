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

void draw(int h, int w){
    rep(i, h){
        if(i==0 || i==h-1) cout << string(w, '#') << endl;
        else cout << '#' + string(w-2, '.') + '#' << endl;
    }
    cout << endl;
}

int main() {
    while(true){
        int h, w;
        cin >> h >> w;
        if(h==0 && w==0) break;
        draw(h, w);
    }
    return 0;
}