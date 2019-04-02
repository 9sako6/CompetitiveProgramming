N=int(input())
A = list(map(int, input().split()))
A.sort()
sa = []
for i in range(N-1):
    diff = A[i+1]-A[i]
    if diff > 0:
        sa.append(diff)
sa.sort()

if len(sa)>=2:
    score = sa[1] - sa[0]
    if score <= 0:
        print(sa[0])
    else:
        dai = max(score, sa[0])
        sho = min(score, sa[0])
        while dai-sho > 0:
            dai, sho = sho, dai-sho
            if dai <= sho:
                dai, sho = sho, dai
        print(dai-sho if dai-sho > 0 else sho)
elif len(sa) == 1:
    dai = max(A[0], sa[0])
    sho = min(A[0], sa[0])
    while dai-sho > 0:
        dai, sho = sho, dai-sho
        if dai <= sho:
            dai, sho = sho, dai
    print(dai-sho if dai-sho > 0 else sho)
else:
    print(A[0])


