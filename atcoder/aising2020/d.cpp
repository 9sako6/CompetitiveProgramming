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
    string x;
    cin >> x;
    if ((int)x.size() < n) {
        string s(n - (int)x.size(), '0');
        x = s + x;
    }
    int popcount = 0;
    rep(i, n) {
        if (x[i] == '1') popcount++;
    }
    cout << popcount << endl;
    int d = 0;
    int t = popcount;
    while (t > 0) {
        d++;
        t /= 2;
    }
    string sub_x = x.substr(n - d - 1, d + 1);
    cout << x << endl;
    ll y = stoi(sub_x, NULL, 2);
    rep(i, n) {
        int pc = popcount + (x[i] == '1' ? -1 : 1);
        int ans = 1;
        ll z = y;
        if (i >= n - d - 1) {
            int b = i - (n - d - 1);
            if (z && (1LL << b)) {
                // bit 1
                z &= ~(1 << b);
            } else {
                z |= (1 << b);
            }
        }
        ll tmp = z % pc;
        while (tmp > 0) {
            pc = __builtin_popcount(tmp);
            tmp %= pc;
            ans++;
        }
        printf("%d\n", ans);
        continue;
    }
    return 0;
}
