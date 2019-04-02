n = int(input())
t, a = list(map(int, input().split()))
H = list(map(int, input().split()))

h = 9999999
index = -1
for i, Hi in enumerate(H):
    if abs(a - (t - 0.006*Hi)) <= abs(a - (t - 0.006*h)):
        h = Hi
        index = i + 1
print(index)
