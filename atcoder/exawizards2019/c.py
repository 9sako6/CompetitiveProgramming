# TLEだよ

import numpy as np

N, Q = map(int, input().split())
_s = list(input())
s2i = {}
smemo = np.ones(N)
for id, c in enumerate(_s):
    if s2i.get(c):
        s2i[c].append(id)
    else:
        s2i[c] = [id]

for i in range(Q):
    t, d = input().split()
    if s2i.get(t) == None:
        continue
    else:
        for i in s2i[t]:
            kazu = smemo[i]
            if d == 'L':
                if i == 0:
                    smemo[i] = 0
                else:
                    smemo[i-1] += kazu
                    smemo[i] = 0
            if d == 'R':
                if i == N-1:
                    smemo[N-1] = 0
                else:
                    smemo[i+1] += kazu
                    smemo[i] = 0

print(int(np.sum(smemo)))