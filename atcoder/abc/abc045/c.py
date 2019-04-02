s = list(map(int,list(input())))

if len(s) == 1:
    print(s[0])
    exit()

from collections import deque

cands=deque([[0],[1]])

while len(cands[0]) != len(s)-1:
    newcands = []
    for cand in cands:
        newcands.append(cand+[0])
        newcands.append(cand+[1])
    cands = newcands

memo = []
while cands:
    pos = cands.pop()
    siki = ''
    for i, p in enumerate(pos):
        siki += str(s[i])
        if p == 1:
            siki += '+'
    siki += str(s[-1])
    memo.append(eval(siki))

print(sum(memo))



    


