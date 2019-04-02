x1, y1, x2, y2 = list(map(int, input().split()))
a = x2 - x1
b = y2 - y1
x3 = (x2 - b)
y3 = (y2 + a)
print(x3, y3, (x3 - (y3 - y2)), (y3 + (x3 - x2)))
