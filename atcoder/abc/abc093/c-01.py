from collections import deque

a, b, c = map(int, input().split())

def bfs(a, b, c):
    cnt = 0
    queue = deque([[a, b, c, cnt]])

    while queue:
        a, b, c, cnt = queue.popleft()
        if a == b and b == c:
            return cnt
        if a >= 60 or b >= 60 or c >= 60:
            return cnt

        if b > a and b > c:
            queue.append([a+1, b, c+1, cnt+1])
        elif a > b and a > c:
            queue.append([a, b+1, c+1, cnt+1])
        elif c > a and c > b:
            queue.append([a+1, b+1, c, cnt+1])
        elif a < b:
            queue.append([a+2, b, c, cnt+1])
        elif b < c:
            queue.append([a, b+2, c, cnt+1])
        elif c < a:
            queue.append([a, b, c+2, cnt+1])

print(bfs(a, b, c))
