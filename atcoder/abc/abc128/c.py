def make_cands(num, cands=[[0],[1]]):
    if len(cands[0]) == num:
        return cands
    else:
        newcands = []
        for cand in cands:
            newcands.append(cand+[0])
            newcands.append(cand+[1])
        return make_cands(num, newcands)

N,M = map(int, input().split())
switches = []
for _ in range(M):
    ks = list(map(int, input().split()))
    switches.append(ks[1:])
p = list(map(int, input().split()))
ans = 0
ress = make_cands(N)
for res in ress:
    tentou = 0
    for sw_i, sw in enumerate(switches):
        cnt = 0
        for num in sw:
            cnt += res[num-1]
        tentou += 1 if cnt % 2 == p[sw_i] else 0
    if tentou == M:
        ans += 1

print(ans)
