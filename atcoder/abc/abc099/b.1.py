a,b=map(int, input().split())
h=[0]*999
h[0]=1
for i in range(1, 999):
    h[i] = (i+1) +h[i-1]
sa = b-a
print(h[sa-1]-b)