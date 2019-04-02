n,k=map(int, input().split())
num=[0]*100001
for i in range(n):
    a,b = map(int, input().split())
    num[a] +=b
cnt = 0
for i in range(1, 100001):
    cnt += num[i]
    if cnt >= k:
        print(i)
        exit()


