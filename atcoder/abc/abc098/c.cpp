#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> w(N+1, 0);
    vector<int> e(N+1, 0);
    rep(i, N) {
        if(S[i]=='W') {
            w[i+1] = w[i] + 1;
            e[i+1] = e[i];
        } else {
            w[i+1] = w[i];
            e[i+1] = e[i] + 1;
        }
    }
    int cnt = 10000000;
    for(int i = 0; i < N; i++) {
        int cw, ce;
        cw = w[i] - w[0];
        ce = e[N] - e[i+1];
        cnt = min(cnt, cw+ce);
    }
    cout << cnt << endl;
    return 0;
}