#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    string s;
    string ans;
    cin >> s;
    rep(i, s.size()) {
        if (s[i] == 'B') {
            if (ans.size()>0) ans = ans.substr(0, ans.size()-1);
        } else {
            ans += s[i];
        }
    }
    cout << ans << endl;

    return 0;
}