#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char *argv[]) {
    cout << std::fixed << std::setprecision(12);
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

struct V {
    double x, y;
    V(double x = 0, double y = 0) : x(x), y(y) {}
    V &operator+=(const V &v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    V operator+(const V &v) const { return V(*this) += v; }
    double dot(const V &v) const { return v.x * x + v.y * y; }
    double cross(const V &v) const { return x * v.y - v.x * y; }
    int ort() const {  // orthant
        if (y > 0) {
            return x > 0 ? 1 : 2;
        } else {
            return x > 0 ? 4 : 3;
        }
    }
    double norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }

    bool operator<(const V &v) const {
        int o = ort(), vo = v.ort();
        if (o != vo) return o < vo;
        return cross(v) > 0;
    }
    friend ostream &operator<<(ostream &os, const V &v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
    friend istream &operator>>(istream &is, V &v) {
        is >> v.x >> v.y;
        return is;
    }
};

void main_sub(void) {
    int n;
    cin >> n;
    vector<V> v(n);
    rep(i, n) cin >> v[i];
    sort(all(v)); // 偏角ソート
    double ans = 0;
    rep(l, n) {
        int r = l;
        V now;
        rep(i, n) {
            now += v[r];
            ans = max(ans, now.norm());
            r = (r + 1) % n;
        }
    }
    cout << ans << endl;
    return;
}