a,b,t=map(int, input().split())
t+=0.5
time = a
i = 1
ans = 0
while time < t:
    ans+=b
    i+=1
    time+=a
print(ans)