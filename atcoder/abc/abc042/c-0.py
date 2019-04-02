N, K = map(int, input().split())
D = list(map(int, input().split()))

can_use = []
for i in range(10):
    if i not in D:
        can_use.append(i)

ans = []
t = 0
for i, dig in enumerate(list(str(N))):
    m = 10
    for cu in can_use:
        sa = cu - int(dig)
        if sa <= m and sa >= 0:
            m = sa
            ans.append(cu)
            if abs(len(list(str(N)))-1-i) == 0:
                break
            t += cu*10**abs(len(list(str(N)))-1-i)
            tmp = t + int(str(can_use[0])*abs(len(list(str(N)))-1-i))
            if tmp >= N:
                print(tmp)
                exit()

if len(ans) < len(list(str(N))):
    min_not0 = can_use[1] if can_use[0] == 0 else can_use[0]
    print(str(min_not0)+str(can_use[0])*len(list(str(N))))
    exit()

print(''.join(map(str, ans[::-1])))
