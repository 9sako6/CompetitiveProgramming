x1, y1, x2, y2 = list(map(int, input().split()))
a = x1 - x2
b = y1 - y2
c = x2 - x1
d = y2 - y1

print('{} {} {} {}'.format(x2 + b, y2 + c, x1 + b, y1 + c))
