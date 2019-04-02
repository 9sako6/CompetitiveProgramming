def make_cands(num, cands=[[0],[1]]):
    if len(cands[0]) == num:
        print(cands)
        return cands
    newcands = []
    for cand in cands:
        newcands.append(cand+[0])
        newcands.append(cand+[1])
    make_cands(num, newcands)
    return newcands


print(make_cands(2))