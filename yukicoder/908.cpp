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
#include <cassert>
#include <climits>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  getline(cin, s);
  rep(i, s.size()){
    if(i & 1){
      if(s[i] != ' ') {
        cout << "No" << endl;
        return 0;
      }
    }else{
      if(!((0 <= (s[i] - 'a')) && ((s[i] - 'a') < 26))){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}