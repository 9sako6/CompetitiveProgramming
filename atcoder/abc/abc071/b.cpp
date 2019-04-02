#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1<<30);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int alfabets[26];
int main() {
    string s;
    cin >> s;
    rep(i, s.size()){
        alfabets[(int)s[i] - 97] += 1;
    }
    rep(i, 26){
        if (alfabets[i] == 0){
            cout << (char)(i+97) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}