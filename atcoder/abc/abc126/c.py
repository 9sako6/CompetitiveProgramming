n,k=map(int, input().split())
def sisu(num, goal):
    cnt = 0
    while num < goal:
        cnt+=1
        num*=2
    return cnt

ans = 0
for i in range(n):
    ans += (1/2)**(sisu(i+1, k))

print(ans/n)
