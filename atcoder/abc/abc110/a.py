l = [int(i) for i in input().split()]
# sort()は破壊的です
# sorted()は破壊的じゃないです
l.sort(reverse=True)
print(l[0]*10 + l[1] + l[2])
