#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a = perm(n);

  for (int i = 0; i < (int)a.size(); ++i) {
    print(a[i]);
  }
  cout << a.size() << endl;

  return 0;
}