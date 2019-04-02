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

template<typename T>
struct RMQ {
    int L;
    vector<T> data;
    const T MAX;
    RMQ(int N, T MAX) : MAX(MAX) {
        L = 1;
        while (L < N) L <<= 1;
        data.assign(L * 2, MAX);
    }
    void update(int i, T x) {
        i += L;
        data[i] = x;
        i >>= 1;
        while (i > 0) {
            data[i] = min(data[i * 2], data[i * 2 + 1]);
            i >>= 1;
        }
    }
    int query(int l, int r, int k, int sl, int sr) {
        if (sr <= l || r <= sl) return MAX;
        if (l <= sl && sr <= r) return data[k];
        T dl = query(l, r, k * 2, sl, (sl + sr) / 2);
        T dr = query(l, r, k * 2 + 1, (sl + sr) / 2, sr);
        return min(dl, dr);
    }
    // min of [l, r)
    int query(int l, int r) { return query(l, r, 1, 0, L); }
    T operator[](const int &k) const {
        return data[k + L];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    RMQ<int> rmq(n, (1<<30) - 1 + (1<<30));
    vector<int> ans;
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (!com) {
            rmq.update(x, y);
        } else {
            ans.push_back(rmq.query(x, y + 1));
        }
    }
    rep(i, ans.size()) cout << ans[i] << endl;

    return 0;
}