N, A, B, C = map(int, input().split())
l = [int(input()) for _ in range(N)]

from collections import deque
q = deque()
q.append([0,0,0,0,0])
mp = []
while q:
    depth, a, b, c, mcnt= q.pop()
    if depth == N:
        mp.append(abs(A-a)+abs(B-b)+abs(C-c)+mcnt*10-30 if min(a,b,c) > 0 else 10**9)
    else:
        q.append([depth+1, a, b, c,mcnt])
        q.append([depth+1, a+l[depth], b, c,mcnt+1])
        q.append([depth+1, a, b+l[depth], c,mcnt+1])
        q.append([depth+1, a, b, c+l[depth],mcnt+1])

print(min(mp))
