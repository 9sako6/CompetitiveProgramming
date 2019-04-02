#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  cout << n % MOD << endl;
  cout << (-n) % MOD << endl;
  cout << (MOD - (-n) % MOD) << endl;
  cout << (MOD - (-n) % MOD) % MOD << endl;
}
