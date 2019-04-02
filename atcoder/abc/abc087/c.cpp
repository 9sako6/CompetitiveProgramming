#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N; cin >> N;
    int a[2][N];
    rep(i, 2){
        rep(j, N) cin >> a[i][j];
    }
    int ans = 0;
    rep(i, N){
        int tmp = 0;
        for(int j=0; j<=i; j++) tmp += a[0][j];
        for(int j=i; j<N; j++) tmp += a[1][j];
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}