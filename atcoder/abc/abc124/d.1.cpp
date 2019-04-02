#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 60;

int main() {
    int N,K;
    string S;
    cin >> N >> K;
    cin >> S;
    
    vector<int> Nums;
    int now = 1;
    int cnt = 0;

    rep(i, N) {
        if(S[i] == (char)('0')+now) cnt++;
        else {
            Nums.push_back(cnt);
            now = 1 - now;
            cnt = 1;
        }
    }
    if (cnt!=0) Nums.push_back(cnt);
    if (Nums.size()%2==0) Nums.push_back(0);
    int Add = 2*K+1;
    int ans = 0;

    vector<int> sum(Nums.size()+1);
    rep(i, Nums.size()) {
        sum[i+1] = sum[i]+Nums[i];
    }
    
    for(int i = 0; i < (int)Nums.size(); i+=2) {
        int left = i;
        int right = min(i+Add, (int)Nums.size());
        int tmp = sum[right] - sum[left];
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}