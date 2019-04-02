from collections import deque
N = int(input())
q = deque()
q.append(0)
memo = []
while q:
    x = q.pop()
    if x < 10**9:
        if len(set(str(x))) == 3:
            memo.append(x)
        q.append(10*x+3)
        q.append(10*x+5)
        q.append(10*x+7)

print(len([num for num in memo if num <= N]))
