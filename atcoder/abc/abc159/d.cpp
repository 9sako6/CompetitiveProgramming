#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char* argv[]) {
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
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int all_cnt = 0;
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
        auto k = itr->first;
        auto v = itr->first;
        cout << "k: " << k << "v: " << v << endl;
        all_cnt += v * (v - 1) / 2;
    }
    cout << all_cnt << endl;
    rep(i, n) { cout << all_cnt - (cnt[a[i]] - 1) << endl; }

    return;
}