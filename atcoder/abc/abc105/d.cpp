#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N,M;
    scanf("%d%d", &N, &M);
    int A[N];
    rep(i, N) scanf("%d", A+i);
    map<int, int> m;
    int SUM[N+1];
    SUM[0]=0;
    rep(i, N){
        SUM[i+1] = (SUM[i] + A[i])%M;
    }
    ll ans = 0;
    rep(i, N+1){
        ans += m[SUM[i]];
        m[SUM[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}