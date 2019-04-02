#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    ll n; cin >> n;
    if (n % 2==0) cout << n << endl;
    else cout << n*2 << endl;

    return 0;
}