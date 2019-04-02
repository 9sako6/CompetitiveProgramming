a = input()
n = list(input())
maxnum = -1
for i in range(len(n)):
    x = set(n[:i])
    y = set(n[i:])
    maxnum = max(maxnum, len(x & y))

print(maxnum)

