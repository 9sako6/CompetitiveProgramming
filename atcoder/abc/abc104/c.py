import math
D, G = list(map(int, input().split()))
p, c, s = [0]*D, [0]*D, [0]*D

for i in range(D):
    p[i], c[i] = list(map(int, input().split()))
    s[i] = 100*(i+1)

slv = [[0], [1]]
for i in range(D-1):
    slv = list(map(lambda x: x+[0], slv)) + list(map(lambda x: x+[1], slv))
memo = []
ans = 10**10 # 比較対象
for si in slv:
    score, cnt = 0, 0
    for i, toku in enumerate(si):
        if toku ==1:
            cnt += p[i]
            score += c[i] + p[i]*100*(i+1)
    if score >= G and cnt <= ans:
        ans = cnt
    memo.append((score, cnt, si))

leqG = []
for m in memo:
    if m[0] < G:
        leqG.append(m)

ans_cand = 10**10
for l in leqG:
    for i, t in enumerate(l[2][::-1]):
        index = len(l[2])-i-1
        if t == 0:
            if l[0]+p[index]*(index+1)*100 >= G:
                ans_tmp = l[1] + min(math.ceil((G-l[0])/((index+1)*100)), p[index])
                ans_cand = min(ans_cand, ans_tmp)
            break
print(min(ans, ans_cand))