#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int N,K;
int T[10][10];
int main() {
    cin >> N >> K;
    rep(i, N)rep(j, K) cin >> T[i][j];
    string ans = "Nothing";
    stack<pair<int, int> > s;
    s.push(make_pair(0,0));
    while(!s.empty()){
        pair<int, int> tmp = s.top();
        s.pop();
        if(tmp.first == N){
            if(tmp.second == 0) ans = "Found";
        }else{
            rep(i, K) s.push(make_pair(tmp.first+1, tmp.second^T[tmp.first][i]));
        }
    }
    cout << ans << endl;
    return 0;
}
