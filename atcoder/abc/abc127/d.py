N,M = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
x = []
for _ in range(M):
    b,c = map(int, input().split())
    x.extend([c]*b)

x.sort(reverse=True)

i = 0
l = len(x)
while i < l and a[i] < x[i]:
    i += 1

print(sum(x[:i])+ sum(a[i:]))