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
#define USE_STRICT_INT
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
    string s;
    cin >> s;
    int n = s.size();
    deque<int> d(n);
    rep(i, n) { d[i] = s[i] - 'a'; }
    int q;
    cin >> q;
    bool hanten = false;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            hanten = !hanten;
        } else {
            int f;
            cin >> f;
            char c;
            cin >> c;
            if (hanten) {
                if (f == 2) {
                    d.push_front(c - 'a');
                } else {
                    d.push_back(c - 'a');
                }
            } else {
                if (f == 1) {
                    d.push_front(c - 'a');
                } else {
                    d.push_back(c - 'a');
                }
            }
            ++n;
        }
    }
    if (hanten) {
        for (int i = n - 1; i >= 0; --i) {
            printf("%c", d[i] + 'a');
        }
        printf("\n");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%c", d[i] + 'a');
        }
        printf("\n");
    }
    return;
}