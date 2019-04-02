from collections import deque

def bfs():
    I = lambda:map(int, input().split())
    R, C = I()
    sy,sx = I()
    gy,gx = I()
    c = [list(input()) for _ in range(R)]
    # print(R, C, sy, sx, gy, gx, c)
    q = deque()
    cnt = 0
    q.append([sx-1,sy-1,cnt])
    while q:
        x,y,cnt = q.popleft()
        for dx,dy in [[1,0],[0,1],[-1,0],[0,-1]]:
            nx,ny = x+dx,y+dy
            if 0 <= nx < C and 0 <= ny < R and c[ny][nx] == '.':
                if nx == gx-1 and ny == gy-1:
                    print(cnt+1)
                    exit()
                q.append([nx,ny,cnt+1])
                c[ny][nx] = '@'

bfs()
