#TLE

ans = []
N, Q = map(int, input().split())
s = input()
for i in range(Q):
    l, r = map(int, input().split())
    s_q = s[l-1:r]
    ans.append( \
        (len(s_q) - len(s_q.replace('AC', '')) ) \
            // 2)

print('\n'.join(map(str, ans)))