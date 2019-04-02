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
    int a, b;
    cin >> a >> b;
    if (a < 0) {
        if (b >= 0) {
            cout << "Zero" << endl;
        } else {
            cout << (((b - a) % 2 == 0) ? "Negative" : "Positive") << endl;
        }
    } else {
        if (a == 0) {
            cout << "Zero" << endl;
        } else {
            cout << "Positive" << endl;
        }
    }
    return 0;
}
