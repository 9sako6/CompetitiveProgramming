#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vector<int> idx(n);
    rep(i, n) idx[a[i]] = i;
    ll ans = 0;
    set<int> s;
    for (int x = n - 1; x >= 0; --x) {
        int i = idx[x];
        ll c = 0;
        {  // calc c
            s.insert(i);
            vector<int> l(2, -1);
            vector<int> r(2, n);
            {  // calc l
                auto it = s.find(i);
                rep(j, 2) {
                    if (it == s.begin()) break;
                    --it;
                    l[j] = *it;
                }
            }
            {  // calc r
                auto it = s.find(i);
                rep(j, 2) {
                    ++it;
                    if (it == s.end()) break;
                    r[j] = *it;
                }
            }
            vector<int> ls(2);
            ls[0] = i - l[0];
            ls[1] = l[0] - l[1];
            vector<int> rs(2);
            rs[0] = r[0] - i;
            rs[1] = r[1] - r[0];
            c = (ll)ls[0] * rs[1] + (ll)ls[1] * rs[0];
        }
        ans += c * (x + 1);
    }
    std::cout << ans << endl;

    return 0;
}