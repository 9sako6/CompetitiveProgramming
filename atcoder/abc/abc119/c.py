N,A,B,C=map(int, input().split())
l=[int(input()) for _ in range(N)]

def dfs(num, a, b, c):
    if N == num:
        return abs(A-a)+abs(B-b)+abs(C-c) - 30 if min(a,b,c)>=1 else 10**10
    ret = []
    ret.append(dfs(num+1, a, b, c))
    ret.append(dfs(num+1, a+l[num], b, c)+10)
    ret.append(dfs(num+1, a, b+l[num], c)+10)
    ret.append(dfs(num+1, a, b, c+l[num])+10)
    return min(ret)

print(dfs(0,0,0,0))