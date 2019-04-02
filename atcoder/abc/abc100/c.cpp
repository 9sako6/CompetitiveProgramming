#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int func(int x) {
    int cnt = 0;
    while (x%2==0) {
        cnt++;
        x/=2;
    }
    return cnt;
}

int main() {
    int N; cin >> N;
    int ans = 0;
    rep(i, N){
        int x;
        cin >> x;
        ans += func(x);
    }
    cout << ans << endl;
    
    return 0;
}