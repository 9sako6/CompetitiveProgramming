n=int(input().split()[0])
d=set(input())
while set(str(n))&d:
    n+=1
print(n)