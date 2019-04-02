A = int(input())
B = int(input())
C = int(input())
X = int(input())
cnt = 0
for c in range(0, C+1):
    for b in range(0, B+1):
        for a in range(0, A+1):
            if c*50 + b*100 + a*500 == X:
                cnt += 1

print(cnt)
