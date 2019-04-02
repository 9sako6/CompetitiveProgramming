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
typedef long long ll;
const int INF = (1<<30);
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll com[2020][2020];

int main() {
    com[0][0]=1;
    for(int i=1; i < 2020; ++i){
        for(int j=0; j <= i; ++j){
            com[i][j] += com[i-1][j];
            if(j>0)com[i][j] += com[i-1][j-1];
            com[i][j] %= MOD;
        }
    }
    int N,K;
    cin >> N >> K;
    for(int i=1; i <= K; i++){ // iグループに分ける
        ll cnt = com[K-1][i-1] % MOD; // 青玉をiグループに分ける分け方
        ll cnt_red = 0;
        if(i==1){
            cnt_red += N-K+1;
        }else{
            for(int x=i-1; x<= N-K; x++){ // x は区切るのに使う赤玉
                ll cnt_red_x = max(com[x-1][i-2], 1LL);
                int a = N-K-x;// 区切るのに関係ない赤玉a個
                if(a > 0) cnt_red_x *= (ll)(a+1);
                cnt_red += cnt_red_x;
                cnt_red %= MOD;
            }
        }
        cnt *= cnt_red;
        cout << cnt % MOD << endl;
    }
    return 0;
}
