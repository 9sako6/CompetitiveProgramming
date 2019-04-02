#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    string str;
    cin >> str;
    int n=0,w=0,s=0,e=0;
    rep(i, str.size()){
        if (str[i] == 'N') n++;
        if (str[i] == 'W') w++;
        if (str[i] == 'S') s++;
        if (str[i] == 'E') e++;
    }
    string ans = "Yes";
    if (n==0 && s!=0) ans = "No";
    if (e==0 && w!=0) ans = "No";
    if (s==0 && n!=0) ans = "No";
    if (w==0 && e!=0) ans = "No";
    cout << ans << endl;
    return 0;
}