#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = int64_t;

constexpr int INF = (1 << 30);
constexpr ll INFL = (1LL << 62);
constexpr ll MOD = 1000000007;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    cout << std::fixed << std::setprecision(10);
    int n;
    cin >> n;
    vector<int> ans(n+1, 0);
    rep(x, 300){
        if(x == 0) continue;
        rep(y, 300){
            if (y == 0) continue;
            rep(z, 300){
                if (z == 0) continue;
                int t = x*x + y*y + z*z + x*y + y*z + z*x;
                if(t <= n){
                    ans[t]++;
                }
            }
        }
    }
    rep(i, n){
        printf("%d\n", ans[i + 1]);
    }
    return 0;
}
