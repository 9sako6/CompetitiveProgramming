#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int a,b;
    cin >> a >> b;
    cout << max({a+b, a-b, a*b}) << endl;

    return 0;
}