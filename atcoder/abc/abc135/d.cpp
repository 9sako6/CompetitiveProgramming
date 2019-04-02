#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const ll INFL = (1LL << 62);
const ll MOD = 1000000007;
ll dp[101010][13];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    dp[0][0] = 1;
    const int N = s.size();
    reverse(all(s));
    int base = 1;
    rep(i, N) {
        if (s[i] != '?') {
            rep(j, 13) {
                int c = s[i] - '0';
                (dp[i + 1][(c * base + j) % 13] += dp[i][j]) %= MOD;
            }
        } else {
            rep(j, 13) {
                rep(k, 10)(dp[i + 1][(k * base + j) % 13] += dp[i][j]) %= MOD;
            }
        }
        base = base * 10 % 13;
    }
    cout << dp[N][5] << endl;

    return 0;
}
