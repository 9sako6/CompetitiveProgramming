#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int H,W,N;
    cin >> H >> W;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    vector<int> b;
    rep(i, N){
        rep(j, a[i]) b.push_back(i+1);
    }
    rep(i, H){
        if (i%2==0){
            rep(j, W){
                cout << b[i*W+j] << " ";
            }
        } else {
            for(int j=W-1; j>=0; j--) cout << b[i*W+j] << " ";
        }
        cout << endl;
    }
    return 0;
}