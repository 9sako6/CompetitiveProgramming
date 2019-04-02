#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N,K;
    cin >> N >> K;
    int a[N];
    rep(i, N) cin >> a[i];
    ll sum[N+1];
    sum[0] = 0;
    rep(i, N) sum[i+1] = sum[i] + (ll)a[i];
    ll ans = 0;
    rep(i, N){
        int it = lower_bound(sum+i, sum+N+1, K+sum[i]) - sum;
        ans += N+1-it;
    }
    cout << ans << endl;
    return 0;
}