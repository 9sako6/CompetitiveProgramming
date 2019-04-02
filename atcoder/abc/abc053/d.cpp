#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }

  int ans = mp.size();
  int tmp = 0;
  // 最後の要素が偶数個か
  bool flag;
  for(auto e : mp) {
    flag  = false;
    int t = e.second-tmp;
    // if(t == 0) ans--;
    if(t%2 == 0){
      tmp = 1;
      flag = true;
      continue;
    }
    tmp = 0;
  }

  cout << max(1, ans-(flag ? 1 : 0)) << '\n';
  return 0;
}
