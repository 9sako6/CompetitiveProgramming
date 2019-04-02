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
const int MOD = 1000000007;
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> ll mod_pow(ll a, ll n, T mod) { mod=(ll)mod; ll res=1, p=a%mod; while(n){ if(n&1) res=res*p%mod; p=p*p%mod; n>>=1; } return res; }


using Real = long double;
using Point = complex<Real>;
using Segment = pair<Point, Point>;
template<class T>
T sq(T x){return x*x; }

Real length(Segment l){
    return abs(l.second - l.first);
}

Real prod(Point x, Point y){
    return real(conj(x) * y);
}

Point proj(Segment l, Point p){
    Real ratio = prod(l.second - l.first, p - l.first) / sq(length(l));
    return l.first + (l.second - l.first) * ratio;
}

int main() {
    cout << fixed << setprecision(10);
    Real x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment l = make_pair(Point(x1,y1), Point(x1, y2));
    int q; cin >> q;
    rep(i, q){
        Real x, y;
        cin >> x >> y;
        Point p(x, y);
        Point ret = proj(l, p);
        cout << ret.real() << " " << ret.imag() << endl;
    }
    return 0;
}