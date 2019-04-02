n=int(input())
k=int(input())
x=int(input())
y=int(input())

if k >= n:
    print(x*n)
else:
    print(k*x+(n-k)*y)
