a, b, c, d = list(map(int, input().split()))

if abs(a - c) <= d:
    print('Yes')
elif abs(a - b) <= d and abs(c - b) <= d:
    print('Yes')
else:
    print('No')
