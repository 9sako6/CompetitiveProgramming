#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    rep(i, n) { cin >> a.at(i); }
    vector<i64> sum(n + 1, 0);
    rep(i, n) { sum[i + 1] += sum[i] + a[i]; }

    i64 ans = 1e15;

    // 真ん中を決める
    for (int i = 2; i < n - 1; ++i) {
        // i:
        // a0  a1 | a2 | a3 | a4  a5
        //        2    3    4
        // 左側は[0, i)
        // 右側は[i, n)
        vector<i64> pqrs;
        {
            // 左側
            double half = sum[i] / 2.0;
            int index = lower_bound(sum.begin(), sum.end(), half) - sum.begin();
            if (index == i || abs(sum[i] - 2 * sum[index]) >
                                  abs(sum[i] - 2 * sum[index - 1])) {
                --index;
            }
            pqrs.push_back(sum[i] - sum[index]);
            pqrs.push_back(sum[index]);
        }
        {
            // 右側
            double half = (sum[n] + sum[i]) / 2.0;
            int index = lower_bound(sum.begin(), sum.end(), half) - sum.begin();
            if (index == n || abs(sum[n] + sum[i] - 2 * sum[index]) >
                                  abs(sum[n] + sum[i] - 2 * sum[index - 1])) {
                --index;
            }
            pqrs.push_back(sum[n] - sum[index]);
            pqrs.push_back(sum[index] - sum[i]);
        }
        sort(pqrs.begin(), pqrs.end());
        ans = min(ans, pqrs[3] - pqrs[0]);
    }
    cout << ans << endl;
    return 0;
}