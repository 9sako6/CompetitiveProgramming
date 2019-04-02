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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> C(N, 0), S(N, 0), F(N, 1);
    rep(i, N-1){
        cin >> C[i] >> S[i] >> F[i];
    }
    rep(i, N){
        if(i==N-1){
            cout << 0 << endl;
            return 0;
        }
        int a = S[i];
        for(int j=i; j < N; ++j){
            a = max(S[j], a);
            if(a%F[j] != 0) a = a+F[j]-(a%F[j]);
            a += C[j];
        }
        cout << a << endl;
    }
}