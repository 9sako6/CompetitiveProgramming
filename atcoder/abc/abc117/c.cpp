#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> x;
    rep(i, M){
        int t;
        cin >> t;
        x.push_back(t);
    }
    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    vector<int> kyori;
    rep(i, M-1){
        kyori.push_back(-x[i+1]+x[i]);
    }
    int ans = x[M-1] - x[0];
    
    sort(kyori.begin(), kyori.end());
    rep(i, N-1){
        ans += kyori[i];
    }
    cout << ans << endl;

    return 0;
}