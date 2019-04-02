w = list(input())
for c in w:
    if w.count(c) % 2 != 0:
        print('No')
        exit()

print('Yes')
