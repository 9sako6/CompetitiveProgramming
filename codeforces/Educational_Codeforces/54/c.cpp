#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  double ds[n];
  rep(i, n) { cin >> ds[i]; }
  rep(i, n) {
    double d = ds[i];
    if (pow(d, 2) - 4 * d < 0) {
      cout << "N" << endl;
    } else {
      double t = sqrt(pow(d, 2) - 4 * d);
      {
        double a = (d - t) / 2;
        double b = d - a;
        if (a >= 0 && b >= 0) {
          printf("Y %.10f %.10f\n", b, a);
        }
        continue;
      }
      {
        double a = (d + t) / 2;
        double b = d - a;
        if (a >= 0 && b >= 0) {
          printf("Y %.10f %.10f\n", b, a);
        }
        continue;
      }
      cout << "N" << endl;
    }
  }

  return 0;
}