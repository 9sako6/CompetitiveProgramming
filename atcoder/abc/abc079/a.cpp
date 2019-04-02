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
    int N;
    cin >> N;
    int x = N / 1000, y = (N % 1000) / 100, z = (N % 100) / 10, w = N % 10;
    if ((x == y && y == z) || (y==z && y==w)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}