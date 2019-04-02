from collections import deque

a, b, c = list(map(int, input().split()))

def bfs(a, b, c):
    cnt = 0
    queue = deque([[a, b, c, cnt]])
    print(queue.popleft())

    while queue:
        pass


bfs(a, b, c)