a, b = list(map(int, input().split()))

h = [0]
for i in range(1, 1000):
    h.append(i+h[i-1])

print(h[b-a]-b)
