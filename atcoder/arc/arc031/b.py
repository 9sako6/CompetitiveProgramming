A = [list(input()) for _ in range(10)]

from collections import deque
import copy as cp

ol = []
for y in range(10):
    for x in range(10):
        if A[y][x] == 'o':
            ol.append("{}-{}".format(x,y))

for j in range(10):
    for i in range(10):
        _A = cp.deepcopy(A)
        m = _A[j][i]
        q = deque()
        can = []
        q.append([i,j])
        _A[j][i] = 'o'
        while q:
            x,y = q.popleft()
            for dx,dy in [[1,0],[0,1],[-1,0],[0,-1]]:
                nx,ny = x+dx,y+dy
                if 0 <= nx < 10 and 0 <= ny < 10 and _A[ny][nx] == 'o':
                    can.append("{}-{}".format(nx,ny))
                    q.append([nx,ny])
                    _A[ny][nx] = '@'

        if "{}-{}".format(i,j) in can:
            can.remove("{}-{}".format(i,j))

        if sorted(ol) == sorted(can):
            print('YES')
            exit()
print('NO')
