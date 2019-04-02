#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    string s; cin >> s;
    int cnt=0;
    rep(i, s.size()) {
        if (s[i] == '+') cnt ++;
        else cnt--;
    }
    cout << cnt << endl;
    return 0;
}