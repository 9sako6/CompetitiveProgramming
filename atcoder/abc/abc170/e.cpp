#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = int64_t;

constexpr int INF = (1 << 30);
constexpr ll INFL = (1LL << 62);
constexpr ll MOD = 1000000007;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

struct Child {
    int id;
    int rate;
    int kinda;
    Child() : id(-1), rate(INF), kinda(-1){};
    Child(int _id, int _rate, int _kinda)
        : id(_id), rate(_rate), kinda(_kinda) {}
    friend bool operator<(const Child &lhs, const Child &rhs) {
        return lhs.rate < rhs.rate;
    }
    friend bool operator>(const Child &lhs, const Child &rhs) {
        return lhs.rate > rhs.rate;
    }
    friend bool operator==(const Child &lhs, const Child &rhs) {
        return lhs.rate == rhs.rate;
    }
};
const int MAX = 2000000;

int main() {
    cout << std::fixed << std::setprecision(10);
    int n, q;
    cin >> n >> q;
    multiset<Child> equals;
    vector<Child> children;
    vector<multiset<Child>> kinda_set(MAX, multiset<Child>{});

    rep(i, n) {
        int a, b;
        cin >> a >> b;
        b--;
        kinda_set[b].insert(Child{i, a, b});
        children.push_back(Child{i, a, b});
    }
    auto getMax = [&](int i) {
        if (kinda_set[i].size() == 0) return Child{-1, INF, -1};
        return *kinda_set[i].rbegin();
    };
    rep(i, MAX) {
        if (kinda_set[i].empty()) continue;
        equals.insert(getMax(i));
    }
    rep(i, q) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        int before_kinda = children[c].kinda;
        equals.erase((*kinda_set[before_kinda].rbegin()));
        if (!kinda_set[before_kinda].empty())
            kinda_set[before_kinda].erase(children[c]);
        equals.insert(getMax(before_kinda));

        equals.erase(getMax(d));
        kinda_set[d].insert(children[c]);
        equals.insert(getMax(d));

        cout << (*equals.begin()).rate << endl;
    }
    return 0;
}
