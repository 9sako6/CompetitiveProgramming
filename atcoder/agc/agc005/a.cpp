#include <iostream>

using namespace std;

int main() {
    string x;
    cin >> x;
    int s_cnt = 0, t_cnt = 0;
    int last_s = -1;
    int first_t = -1;
    if (x.back() == 'S') {
        last_s = (int)x.size() - 1;
        while (last_s >= 0 and x[last_s] == 'S') {
            last_s--;
        }
        last_s++;
    }
    if (x.front() == 'T') {
        first_t = 0;
        while (first_t < (int)x.size() and x[first_t] == 'T') {
            first_t++;
        }
        first_t--;
    }

    if (last_s < 0 and first_t < 0) {
        for (auto &c : x) {
            if (c == 'S')
                s_cnt++;
            else
                t_cnt++;
        }
        cout << (int)x.size() - 2 * min(s_cnt, t_cnt) << endl;
        return 0;
    } else if ((last_s < 0 and first_t > 0) or
               (first_t < 0 and last_s > 0)) {  // 全部T or S
        cout << x.size() << endl;
        return 0;
    } else {
        for (int i = first_t + 1; i < last_s; i++) {
            if (x[i] == 'S')
                s_cnt++;
            else
                t_cnt++;
        }
        cout << (int)x.size() - 2 * min(s_cnt, t_cnt) << endl;
        return 0;
    }

    return 0;
}