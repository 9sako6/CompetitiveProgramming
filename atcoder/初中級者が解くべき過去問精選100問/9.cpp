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
    int m;
    cin >> m;
    vector<int> x(m);
    vector<int> y(m);
    rep(i, m) { cin >> x[i] >> y[i]; }
    int n;
    cin >> n;
    vector<int> px(n);
    vector<int> py(n);
    vector<int> cx(n);
    vector<int> cy(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        px[i] = a;
        py[i] = b;
        cx[i] = a - x[0];
        cy[i] = b - y[0];
    }
    sort(all(px));
    sort(all(py));
    int ans_index = -1;
    rep(i, n) {
        bool flag = true;
        rep(j, m) {
            flag = binary_search(all(px), x[j] + cx[i]) &&
                   binary_search(all(py), y[j] + cy[i]);
            if (!flag) {
                break;
            }
            // cout << flag << " " << cx[i] << " " << cy[i] << endl;
        }
        if (flag) {
            ans_index = i;
            // cout << "---" << endl;
            // cout << cx[i] << " " << cy[i] << endl;
            break;
        } else {
            continue;
        }
    }
    assert(ans_index != -1);
    cout << cx[ans_index] << " " << cy[ans_index] << endl;

    return;
}