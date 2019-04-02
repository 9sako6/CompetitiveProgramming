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
    int n;
    cin >> n;
    unordered_map<int, int> count;
    vector<int> v(n);
    rep(i, n){
        int a;
        cin >> a;
        v[i] = a;
        count[a]++;
    }
    int first = -1;
    int first_cnt = 0;
    for(auto &p : count){
        if(p.second > first_cnt){
            first_cnt = p.second;
            first = p.first;
        }
    }
    int second = -1;
    int second_cnt = 0;
    for(auto &p : count){
        if(p.second > second_cnt and p.first != first){
            second_cnt = p.second;
            second = p.first;
        }
    }
    int cnt1=0, cnt2=0;
    bool flag = true;
    rep(i, n){
        if(flag){
            if(v[i] != first) cnt1++;
            if(v[i] != second) cnt2++;
        }else{
            if(v[i] != second) cnt1++;
            if(v[i] != first) cnt2++;
        }
        flag = !flag;
    }
    cout << min(cnt1, cnt2) << endl;
    return 0;
}