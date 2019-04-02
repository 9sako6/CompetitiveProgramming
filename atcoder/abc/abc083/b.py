n, a, b = map(int, input().split())
sumnum = 0
for i in range(1, n+1):
    keta = sum(map(int, list(str(i))))
    if keta >= a and keta <= b:
        sumnum += i

print(sumnum)
