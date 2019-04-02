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
    string s;
    int x, y;
    cin >> s >> x >> y;
    const int n = s.size();
    int cnt = 0;
    vector<int> t;
    rep(i, n){
        if(s[i] == 'T'){
            if(cnt != 0) t.push_back(cnt);
            t.push_back(0);
            cnt = 0;
        }else{
            cnt++;
            if(i == n-1) t.push_back(cnt);
        }
    }
    const int MAX = 8080;
    vector<vector<bool>> dpx(MAX, vector<bool>(MAX*2, false));
    vector<vector<bool>> dpy(MAX, vector<bool>(MAX*2, false));
    dpx[0][8000] = true;
    dpy[0][8000] = true;
    bool flag = false, xy = true;
    int cnt_x = 0, cnt_y = 0;
    const int N = t.size();
    rep(i, N){
        if(t[i] == 0){
            xy = !xy;
        }else if(xy){
            cnt_x++;
            rep(j, MAX*2){
                if(dpx[cnt_x-1][j]){
                    if(j+t[i] < MAX*2) dpx[cnt_x][j+t[i]] = true;
                    if(j-t[i] >= 0 && flag) dpx[cnt_x][j-t[i]] = true;
                }
            }
        }else if(!xy){
            cnt_y++;
            rep(j, MAX*2){
                if(dpy[cnt_y-1][j]){
                    if(j+t[i] < MAX*2) dpy[cnt_y][j+t[i]] = true;
                    if(j-t[i] >= 0) dpy[cnt_y][j-t[i]] = true;
                }
            }
        }
        if(!flag) flag = true;
    }
    cout << ((dpx[cnt_x][x+8000] && dpy[cnt_y][y+8000]) ? "Yes" : "No") << endl;

    return 0;
}