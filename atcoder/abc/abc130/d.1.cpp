#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1 << 30);
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    ll k;
    cin >> n;
    cin >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    ll ans = 0;
    int j = 0;
    rep(i, n)
    {
        while (j < n && sum + a[j] < k)
        {
            sum += a[j];
            ++j;
        }
        ans += j-i;
        sum -= a[i];
    }
    ans = (ll)n*(n+1)/2 - ans;
    cout << ans << endl;
    return 0;
}