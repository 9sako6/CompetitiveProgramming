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
int ans;
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H+2);
    S[0] = string(W+2, '#');
    for(int i=1; i < H+1; i++){
        string s;
        cin >> s;
        S[i] = '#' + s + '#';
    }
    S[H+1] = string(W+2, '#');
    int fromLeft[H+2][W+2]={};
    int fromRight[H+2][W+2]={};
    int fromUe[H+2][W+2]={};
    int fromShita[H+2][W+2]={};
    for(int i=1; i <= H; i++){
        int tmp = 0;
        bool sec = false;
        for(int j=1; j <=W; j++){
            if(S[i][j] == '.'){
                if(sec) {
                    ++tmp;
                    fromLeft[i][j] = tmp;
                }else{
                    sec = true;
                    ++tmp;
                    fromLeft[i][j] = tmp;
                }
            }else{
                sec = false;
                tmp = 0;
            }
        }
    }
    for(int i=1; i <= H; i++){
        int tmp = 0;
        bool sec = false;
        for(int j=W; j >= 1; j--){
            if(S[i][j] == '.'){
                if(sec) {
                    ++tmp;
                    fromRight[i][j] = tmp;
                }else{
                    sec = true;
                    ++tmp;
                    fromRight[i][j] = tmp;
                }
            }else{
                sec = false;
                tmp = 0;
            }
        }
    }
    for(int j=1; j <= W; j++){
        int tmp = 0;
        bool sec = false;
        for(int i=1; i <=H; i++){
            if(S[i][j] == '.'){
                if(sec) {
                    ++tmp;
                    fromUe[i][j] = tmp;
                }else{
                    sec = true;
                    ++tmp;
                    fromUe[i][j] = tmp;
                }
            }else{
                sec = false;
                tmp = 0;
            }
        }
    }
    for(int j=1; j <= W; j++){
        int tmp = 0;
        bool sec = false;
        for(int i=H; i >=1; i--){
            if(S[i][j] == '.'){
                if(sec) {
                    ++tmp;
                    fromShita[i][j] = tmp;
                }else{
                    sec = true;
                    ++tmp;
                    fromShita[i][j] = tmp;
                }
            }else{
                sec = false;
                tmp = 0;
            }
        }
    }
    for(int i=1; i <= H; i++){
        for(int j=1; j <=W; j++){
            if(S[i][j] == '.'){
                int yoko, tate;
                yoko = fromLeft[i][j] + fromRight[i][j] - 1;
                tate = fromUe[i][j] + fromShita[i][j] - 1;
                if(yoko + tate -1 > ans) ans = yoko + tate -1;
            }
        }
    }
       
    cout << ans << endl;
    return 0;
}