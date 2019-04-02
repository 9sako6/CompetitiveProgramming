#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    ans += to_string(s.size()-2);
    ans += s[s.size()-1];
    cout << ans << endl;

    return 0;
}