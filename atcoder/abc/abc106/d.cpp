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

vector<vector<int>> sum;
int N, M, Q;
int buildSumTable(const vector<int> &L, const vector<int> &R){
  sum = vector<vector<int>>(N+1, vector<int>(N+1, 0));
  rep(i, M) sum[L[i]][R[i]]++;
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j){
      sum[i][j] += sum[i-1][j];
      sum[i][j] += sum[i][j-1];
      sum[i][j] -= sum[i-1][j-1];
    }
  }
  return 0;
}

int getSumRange(int L, int R){
  int ans = sum[R][R] - sum[R][L-1] - sum[L-1][R] + sum[L-1][L-1];
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M >> Q;
  vector<int> L(M), R(M);
  rep(i, M){
    cin >> L[i] >> R[i];
  }
  buildSumTable(L, R);
  rep(i, Q){
    int p, q;
    cin >> p >> q;
    cout << getSumRange(p, q) << endl;
  }
  return 0;
}