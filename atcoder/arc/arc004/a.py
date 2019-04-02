N = int(input())
xy = [list(map(int, input().split())) for _ in range(N)]

max_len = 0

for i in range(N):
    for j in range(N):
        l = ((xy[i][0]-xy[j][0])**2 + (xy[i][1]-xy[j][1])**2)**0.5
        if l > max_len:
            max_len = l

print(max_len)
