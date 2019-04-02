from collections import deque

H, W = map(int, input().split())
c = [list(input()) for _ in range(H)]

def dfs():
    q = deque()
    # find 's' and 'g'
    for y in range(H):
        for x in range(W):
            if c[y][x] == 's':
                sx, sy = x, y
            elif c[y][x] == 'g':
                gx, gy = x, y

    q.append([sx, sy])
    while q:
        x,y = q.popleft()
        for dx, dy in [[1,0], [0,1], [-1,0], [0,-1]]:
            nx,ny = x+dx, y+dy
            if 0 <= nx < W and 0 <= ny < H and c[ny][nx] != '#':
                if nx == gx and ny == gy:
                    return 'Yes'
                q.append([nx, ny])
                c[ny][nx] = "#"
                # draw_c(c)
    return 'No'

# def draw_c(mat):
#     print('----')
#     for row in mat:
#         print(''.join(row))

print(dfs())
