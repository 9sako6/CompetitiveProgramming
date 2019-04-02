#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> range(101, 0);
    for(int i=a; i <= b; i++) range[i]++;
    for(int i=c; i <= d; i++) range[i]++;
    int cnt = 0;
    rep(i, 101) if(range[i]==2) cnt++;
    cout << (cnt ? cnt-1 : cnt) << endl;
    return 0;
}