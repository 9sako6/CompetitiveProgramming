#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);

int main() {
    int N;
    cin >> N;
    int nowT = 0, nowX = 0, nowY = 0;
    string ans = "Yes";
    rep(i, N){
        int t, x, y;
        cin >> t >> x >> y;
        int dT = t - nowT;
        int dx = abs(x - nowX);
        int dy = abs(y - nowY);
        if (dT < dx + dy) ans = "No";
        int dist = dx + dy;
        if (dist % 2 == 0){
            if (dT % 2 == 1) ans = "No";
        } else {
            if (dT % 2 == 0) ans = "No";
        }
    }
    cout << ans << endl;

    return 0;
}