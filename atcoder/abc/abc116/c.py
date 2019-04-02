N = int(input())
h = list(map(int, input().split()))
ans = 0
now = 1
while now <= max(h):
    kukan = 0
    flag = False # 区間を数え始めていいかどうか
    for i, hi in enumerate(h):
        if hi < now and flag:
            kukan += 1
            flag = False
        elif i == len(h)-1 and hi >= now:
            kukan+=1
        elif hi >= now and flag == False:
            flag = True
    now +=1
    ans += kukan
print(ans)
