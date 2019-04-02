#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a;
    rep(i, N){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> m;
    rep(i, M){
        cin >> m[i][0] >> m[i][1];
    }
    sort(m.begin(), m.end(), greater<>());
    vector<int> x;
    rep(i, (int)m.size()){
        int t = m[i][0];
        int y = m[i][1];
        rep(j, t){
            x.push_back(y);
        }
    }
    int id = 0;
    while (id < (int)x.size() && id < N && a[id] < x[id]){
        a[id] = x[id];
        id++;
    }
    ll ans = 0;
    rep(i, N){
        ans += a[i];
    }    
    cout << ans << endl;
    return 0;
}