#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int a,b;
    cin >> a >> b;
    if(a <= b) cout << a << endl;
    else cout << a-1 << endl;
    return 0;
}