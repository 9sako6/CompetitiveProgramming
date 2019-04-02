#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef int_fast64_t ll;
signed main() {
    int_fast32_t X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    ll A[X], B[Y], C[Z];
    rep(i, X) scanf("%lld", A+i);
    rep(i, Y) scanf("%lld", B+i);
    rep(i, Z) scanf("%lld", C+i);
    vector<ll> AB;
    rep(i, X)rep(j, Y) AB.push_back(A[i]+B[j]);
    sort(AB.begin(),AB.end(),greater<ll>());
    vector<ll> ABC;
    rep(i, min(X*Y, K))rep(j, Z) ABC.push_back(AB[i]+C[j]);
    sort(ABC.begin(),ABC.end(),greater<ll>());
    rep(i, K) printf("%lld\n", ABC[i]);
}