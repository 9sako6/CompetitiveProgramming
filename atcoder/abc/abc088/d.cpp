#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <numeric>
#include <complex>

using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const int INF = (1<<30);
const ll INFL = (1LL<<62);
const ll MOD = 1000000007;
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> ll mod_pow(ll a, ll n, T mod) { mod=(ll)mod; ll res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }
template<int mod>
struct ModInt {
    using ll = long long; ll x;
    ModInt() : x(0) {}
    ModInt(int y) : x(y >= 0 ? ll(y % mod) : (ll)((mod - (-y) % mod))) {}
    ModInt(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
    ModInt &operator+=(const ModInt &rhs) { if((x += rhs.x) >= mod) x -= mod; return *this; }
    ModInt &operator-=(const ModInt &rhs) { if((x += mod - rhs.x) >= mod) x -= mod; return *this; }
    ModInt &operator*=(const ModInt &rhs) { x = x * rhs.x % mod; return *this; }
    ModInt &operator/=(const ModInt &rhs) { *this *= rhs.inverse(); return *this; }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
    ModInt operator==(const ModInt &rhs) const { return x == rhs.x; }
    ModInt operator!=(const ModInt &rhs) const { return x != rhs.x; }
    friend ostream &operator<<(ostream &os, const ModInt &rhs) { return os << rhs.x; }
    friend istream &operator>>(istream &is, ModInt &rhs) { ll t; is >> t; rhs = ModInt<mod> (t); return (is); }
private:
    ModInt inverse() const { ll a = x, u = 1LL, v = 0LL, t, b = (ll)mod; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return  ModInt(u); }
};
using mint = ModInt<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H) cin >> field[i];
    int cnt = 0;
    rep(i, H)rep(j, W) if(field[i][j]=='.') ++cnt;

    deque<vector<int>> q;
    q.push_back({0, 0}); // x, y
    int dist[H][W];
    rep(i, H)rep(j, W) dist[i][j] = INF;
    dist[0][0] = 1;
    int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
    while(!q.empty()){
        bool ok=false;
        vector<int> t = q.front(); q.pop_front();
        int x = t[0], y = t[1];
        rep(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx == W-1 && ny == H-1){
                dist[ny][nx] = dist[y][x] + 1;
                ok=true;
            }else if(0<=nx && nx<W && 0<=ny && ny<H && dist[ny][nx] > dist[y][x]+1 && field[ny][nx] == '.'){
                dist[ny][nx] = dist[y][x] + 1;
                q.push_back({nx, ny});
            }
        }
        if(ok) break;
    }
    if(dist[H-1][W-1] >= INF) cout << -1 << endl;
    else cout << cnt-dist[H-1][W-1] << endl;

    return 0;
}