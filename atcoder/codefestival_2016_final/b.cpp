#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = (1 << 30);

int main(){
    int N;
    scanf("%d", &N);
    int ans = 0;
    int id = 1;
    while (N > ans){
        ans += id;
        id ++;
    }
    for (int i = 1; i < id; i++) {
        if (i == (ans - N)) continue;
        else printf("%d\n", i);
    }
    return 0;
}