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

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30);
const ll INFL = (1LL<<62);
const int MOD = 1000000007;
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> ll mod_pow(ll a, ll n, T mod) { mod=(ll)mod; ll res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }

template<typename T>
void print_vec(const vector<T> &v){
  int sz = v.size();
  for(int i=0; i < sz; i++){
    cout << v[i];
    if(i != sz-1) cout << " ";
  }
  cout << "\n";
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(auto &a : A) cin >> a;
  rep(i, n){
    int j = i-1;
    int v = A[i];
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print_vec(A);
  }
  return 0;
}