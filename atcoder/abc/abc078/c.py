N, M = map(int, input().split())
ans = 0
p = (1/2)**(M)
print(int((1900*M)/p+(N-M)*100/p))