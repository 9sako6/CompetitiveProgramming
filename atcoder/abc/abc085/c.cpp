#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int N,Y;
    cin >> N >> Y;
    rep(i, N+1) {
        rep(j, N+1) {
            if ((N-i-j) >= 0 && 10000*i+5000*j+1000*(N-i-j)==Y) {
                cout << i << ' ' << j << ' ' << N-i-j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}