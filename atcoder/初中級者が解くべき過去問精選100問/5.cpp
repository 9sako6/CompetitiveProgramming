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
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

template <typename T>
T in() {
  T value;
  cin >> value;
  return value;
}

#undef int
int main() {
#define int i64
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a = in<int>();
  int b = in<int>();
  int c = in<int>();
  int x = in<int>();
  int y = in<int>();
  int ans = INF;
  rep(i, pow(10, 5) + 1) {
    int tmp = i * 2 * c + max((i64)(0), x - i) * a + max((i64)(0), y - i) * b;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
