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
template <typename T>
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(g.size(), INF);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while (!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if (dist[idx] < cost) continue;
        for (auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if (dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}
void print() { std::cout << std::endl; }
template <typename T, typename... A>
void print(const T &first, const A &... rest) {
    cout << sizeof...(rest) << endl;
    std::cout << first;
    if (sizeof...(rest)) std::cout << " ";
    print(rest...);
}
template <typename... A>
void print(const A &... rest) {
    print(rest...);
}
template <typename A>
void print(const std::vector<A> &v) {
    std::for_each(v.begin(), v.end(), [](A x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int dp[1 << 17][17];

int rec(vector<vector<int>> &g, int S, int v) {
    if (dp[S][v] >= 0) {
        return dp[S][v];
    }
    int n = g.size();
    if ((S == (1 << n) - 1)) {
        return dp[S][v] = 0;
    }
    int res = INF;
    rep(u, n) {
        if (!(S >> u & 1)) {
            res = min(res, rec(g, (S | (1 << u)), u) + g[v][u]);
        }
    }
    return dp[S][v] = res;
}

int main() {
    cout << std::fixed << std::setprecision(10);
    int n, m;
    cin >> n >> m;
    WeightedGraph<int> g(n);
    rep(i, m) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].emplace_back(u, 1);
        g[u].emplace_back(v, 1);
    }
    int s;
    cin >> s;
    --s;
    int k;
    cin >> k;
    vector<int> t(k);
    map<int, int> node;
    node[s] = 0;
    rep(i, k) {
        cin >> t[i];
        --t[i];
        node[t[i]] = i + 1;
    }

    vector<vector<int>> gnew(k + 1, vector<int>(k + 1, 0));

    auto ds = dijkstra(g, s);
    for (auto ti : t) {
        gnew[node[s]][node[ti]] = ds[ti];
        gnew[node[ti]][node[s]] = ds[ti];
    }
    rep(i, k) {
        auto d = dijkstra(g, t[i]);
        for (auto ti : t) {
            gnew[node[t[i]]][node[ti]] = d[ti];
            gnew[node[ti]][node[t[i]]] = d[ti];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(gnew, 0, node[s]) << endl;
    return 0;
}
