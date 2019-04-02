n = int(input())
l = range(1, n + 1)
gu = l[1::2]
ki = l[::2]
print(len(gu) * len(ki))

