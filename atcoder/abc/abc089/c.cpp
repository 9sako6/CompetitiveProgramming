#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll counter[5];
int main() {
    int N;
    cin >> N;
    rep(i, N){
        string name;
        cin >> name;
        if(name[0] == 'M') counter[0] += 1;
        if(name[0] == 'A') counter[1] += 1;
        if(name[0] == 'R') counter[2] += 1;
        if(name[0] == 'C') counter[3] += 1;
        if(name[0] == 'H') counter[4] += 1;
    }
    ll ans = 0;
    rep(i, 5){
        for(int j=i+1; j < 5; j++){
            for(int k=j+1; k < 5; k++){
                ans += counter[i]*counter[j]*counter[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}