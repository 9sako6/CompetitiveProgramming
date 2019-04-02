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
const int INF = (1 << 30);
const ll INFL = (1LL << 62);
const ll MOD = 1000000007;
template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
template <class T>
ll mod_pow(ll a, ll n, T mod) {
    mod = (ll)mod;
    ll res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
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
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll ans = 0;
    if (s[0] != s[(ll)s.size() - 1]) {
        for (ll i = 1; i < (ll)s.size(); i++) {
            if (s[i - 1] == s[i]) {
                s[i] = '#';
                ans++;
            }
        }
        cout << ans * k << endl;
        return 0;
    } else {
        // 文字が一種類かどうか
        bool flag = false;
        map<char, ll> cnt;
        for (auto& c : s) {
            cnt[c]++;
        }
        for (auto& c : s) {
            if (cnt[c] == (ll)s.size()) flag = true;
        }
        if (flag) {
            if ((ll)s.size() % 2 == 0) {
                cout << (ll)s.size() / 2 * k << endl;
                return 0;
            } else {
                if (k % 2 == 0) {
                    cout << (k / 2) * ((ll)s.size() / 2 + ((ll)s.size() / 2 + 1))
                         << endl;
                } else {
                    cout << (k / 2) * ((ll)s.size() / 2 +
                                       ((ll)s.size() / 2 + 1)) +
                                ((ll)s.size() / 2)
                         << endl;
                }
                return 0;
            }
        } else {
            // 先頭から何文字目まで同じか
            ll front = 1;
            for (ll i = 1; i < (ll)s.size(); i++) {
                if (s[i - 1] == s[i]) {
                    front++;
                } else {
                    break;
                }
            }
            // 末尾から何文字目まで同じか
            ll back = 1;
            for (ll i = (ll)s.size() - 1; i > 0; i--) {
                if (s[i - 1] == s[i]) {
                    back++;
                } else {
                    break;
                }
            }
            string mid(front + back, 'a');
            ll ans_mid = 0;
            for (ll i = 1; i < (ll)mid.size(); i++) {
                if (mid[i - 1] == mid[i]) {
                    mid[i] = '#';
                    ans_mid++;
                }
            }
            ll ans_com = 0;
            for (ll i = front; i <= (ll)s.size() - back; i++) {
                if (s[i - 1] == s[i]) {
                    s[i] = '#';
                    ans_com++;
                }
            }
            ll ans_front = 0;
            ll ans_back = 0;
            if (front > 1) {
                for (ll i = 0; i < front; i++) {
                    if (s[i - 1] == s[i]) {
                        s[i] = '#';
                        ans_front++;
                    }
                }
            }
            if (back > 1) {
                for (ll i = (ll)s.size() - back; i < (ll)s.size(); i++) {
                    if (s[i - 1] == s[i]) {
                        s[i] = '#';
                        ans_back++;
                    }
                }
            }
            cout << ans_com * k + ans_front + ans_back + ans_mid * (k - 1)
                 << endl;
            return 0;
        }
    }

    return 0;
}