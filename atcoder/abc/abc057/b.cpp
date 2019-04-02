#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int N, M;
    cin >> N >> M;
    int a[N], b[N];
    rep(i, N) {
        cin >> a[i] >> b[i];
    }
    int c[M], d[M];
    rep(i, M) {
        cin >> c[i] >> d[i];
    }
    rep(i, N){
        int min_len = 2000000000;
        int min_id = 2000000000;
        for(int j=M-1; j >=0; j--) {
            int kyori = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (kyori <= min_len) {
                min_len = kyori;
                min_id = j;
            }
        }
        cout << min_id+1 << endl;
    }

    return 0;
}