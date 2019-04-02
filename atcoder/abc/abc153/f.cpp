#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char* argv[]) {
    cout << std::fixed << std::setprecision(10);
    main_sub();
    return 0;
}
// int を int64_t にする
// g++ に -DUSE_STRICT_INT をつけるか、
// 下のコメントアウトを外すと無効化
// #define USE_STRICT_INT
using i64 = int64_t;
#ifndef USE_STRICT_INT
#define int i64
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF = (1 << 30);
constexpr i64 INFL = (1LL << 62);
constexpr i64 MOD = 1000000007;

void main_sub(void) {
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<int, int>> x(n);
    rep(i, n) { cin >> x[i].first >> x[i].second; }

    sort(all(x), [](auto const& lhs, auto const& rhs) {
        return lhs.first < rhs.first;
    });
    d = d * 2;
    int tot = 0;
    queue<pair<int, int>> q;
    int ans = 0;
    rep(i, n) {
        int xi = x[i].first;
        int h = x[i].second;
        while (q.size() && q.front().first < xi) {
            tot -= q.front().second;
            q.pop();
        }
        h -= tot;
        if (h > 0) {
            int num = (h + a - 1) / a;
            ans += num;
            int damage = num * a;
            tot += damage;
            q.emplace(xi + d, damage);
        }
    }
    cout << ans << endl;
    // rep(i, n) { cout << x[i].first << " " << x[i].second << endl; }
    return;
}