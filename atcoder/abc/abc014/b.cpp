#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int n, X;
    scanf("%d%d", &n, &X);
    int a[n];
    rep(i, n) scanf("%d", a+i);
    int ans = 0;
    for(int bit = 0; bit < n; ++bit){
        if(X & (1<<bit)) ans += a[bit];
    }
    cout << ans << endl;
    return 0;
}