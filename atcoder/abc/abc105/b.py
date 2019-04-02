n = int(input())

for i4 in range(25):
    for i7 in range(15):
        if n == i4 * 4 + i7 * 7:
            print('Yes')
            quit()

print('No')
