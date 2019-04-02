#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll com[55][55];
int main() {
    com[0][0]=1;
    for(int i=1; i < 55; ++i){
        for(int j=0; j <= i; ++j){
            com[i][j] += com[i-1][j];
            if(j>0)com[i][j] += com[i-1][j-1];
        }
    }
    int N,A,B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll max_sum = 0;
    rep(i, A) max_sum += v[i];
    double ave = (double)(max_sum)/A;
    int num = 0;
    ll ans = 0;
    rep(i, N) if(v[i]==v[A-1]) ++ num;
    if(v[0] == v[A-1]){
        for(int j=A; j<= B; ++j){
            ans += com[num][j]; 
        }
    }else{
        int a = 0;
        rep(i, A) if(v[i]==v[A-1]) ++a;
        ans = com[num][a];
    }
    cout << fixed << setprecision(10) << ave << endl;
    cout << ans << endl;
    return 0;
}
