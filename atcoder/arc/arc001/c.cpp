#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const i64 INFL = (1LL << 62);
const i64 MOD = 1000000007;

vector<vector<int>> perm(int n) {
  vector<vector<int>> res;
  queue<pair<vector<int>, int>> q;
  for (int i = 0; i < n; ++i) {
    int flag = 0;
    flag |= (1 << i);
    vector<int> t;
    t.push_back(i);
    q.push({t, flag});
  }
  // BFS
  while (!q.empty()) {
    pair<vector<int>, int> tmp = q.front();
    q.pop();
    vector<int> t = tmp.first;
    int flag = tmp.second;
    int update = false;
    for (int i = 0; i < n; ++i) {
      if (!(flag & (1 << i))) {
        update = true;
        vector<int> newt = t;
        int newflag = flag;
        newt.push_back(i);
        newflag |= (1 << i);
        q.push({newt, newflag});
      }
    }
    if (!update) {
      res.push_back(t);
    }
  }
  return res;
}
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T& first, const A&... rest) {
  cout << sizeof...(rest) << endl;
  std::cout << first;
  if (sizeof...(rest)) std::cout << " ";
  print(rest...);
}
template <typename... A>
void print(const A&... rest) {
  print(rest...);
}
template <typename A>
void print(const std::vector<A>& v) {
  std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
  std::cout << std::endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<string> c(8);
  vector<int> zahyo(8, -1);
  rep(i, 8) {
    string ci;
    cin >> ci;
    rep(j, 8) {
      if (ci[j] == 'Q') {
        zahyo[j] = i;
      }
    }
  }
  int cnt = 0;
  rep(i, 8) {
    if (zahyo[i] != -1) cnt++;
  }
  if (cnt != 3) {
    cout << "No Answer" << endl;
    return 0;
  }

  vector<vector<int>> p = perm(8);
  for (auto& pi : p) {
    bool huteki = false;
    rep(i, 8) {
      if (zahyo[i] != -1 && zahyo[i] != pi[i]) {
        huteki = true;
      }
    }
    if (huteki) continue;
    unordered_map<int, bool> tashi{};
    unordered_map<int, bool> hiki{};
    rep(i, 8) {
      if (tashi[pi[i] + i] || hiki[pi[i] - i]) {
        huteki = true;
      } else {
        tashi[pi[i] + i] = true;
        hiki[pi[i] - i] = true;
      }
    }
    if (huteki) continue;
    rep(i, 8) {
      rep(j, 8) {
        if (pi[j] == i) {
          cout << 'Q';
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
    return 0;
  }
  cout << "No Answer" << endl;

  return 0;
}