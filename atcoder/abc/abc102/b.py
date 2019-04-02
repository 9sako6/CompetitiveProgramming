n = int(input())
a = list(map(int, input().split()))
max = 0
for a1 in a:
    for a2 in a:
        if max < abs(a1 - a2):
            max = abs(a1 - a2)

print(max)
