#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int c[3][3];

int main() {
  rep(i, 3) cin >> c[i][0] >> c[i][1] >> c[i][2];
  int a[3]={}, b[3]={};
  string ans = "No";
  rep(i, 101){ // a0: [0, 100]
    a[0] = i;
    rep(i, 3) b[i] = c[0][i] - a[0];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];
    bool flag = true;
    rep(i, 3){
      rep(j, 3){
        if (c[i][j] != a[i] + b[j]){
          flag = false;
          break;
        }
      }
    }
    if(flag) ans = "Yes";
  }

  cout << ans << endl;
  return 0;
}