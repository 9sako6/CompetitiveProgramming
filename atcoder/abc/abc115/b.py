N = int(input())

p = [int(input()) for _ in range(N)]
maxp = max(p)
print(int(sum(p) - maxp*0.5))
