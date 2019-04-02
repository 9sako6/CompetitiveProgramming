N=int(input())

e = [0]*(N+1)
for i in range(2, N+1):
    cur = i
    for j in range(2, i+1):
        while cur % j == 0:
            e[j] +=1
            cur //=j

def cnt(n):
    return len(list(filter(lambda x: x>=n-1, e)))

print(cnt(75) + cnt(15)*(cnt(5)-1) + cnt(25)*(cnt(3)-1) + cnt(5) * (cnt(5)-1) * (cnt(3)-2) // 2)



