n=int(input())
a=list(map(int, input().split()))

fusei = 0
cnt = 0
if a[0] > 0:
    cnt = -1
    fusei += abs(a[0])+1
flag = 1
for i in range(1, n):
    if flag == 1:
        ai = a[i]
        if ai > 0:
            if ai + cnt <= 0:
                fusei += abs(cnt) + 1
                cnt = 1
            else:
                cnt += ai
        else:
            fusei += abs(cnt)+1
            cnt = 1
    else:
        ai = a[i]
        if ai < 0:
            if ai + cnt >= 0:
                fusei += abs(cnt) + 1
                cnt = -1
            else:
                cnt += ai
        else:
            fusei += abs(cnt) +1
            cnt = -1



seifu = 0
cnt = 0
if a[0] < 0:
    cnt = 1
    seifu += abs(a[0])+1
flag = -1
for i in range(1, n):
    if flag == 1:
        ai = a[i]
        if ai > 0:
            if ai + cnt <= 0:
                seifu += abs(cnt) + 1
                cnt = 1
            else:
                cnt += ai
        else:
            seifu += abs(cnt)+1
            cnt = 1
    else:
        ai = a[i]
        if ai < 0:
            if ai + cnt >= 0:
                seifu += abs(cnt) + 1
                cnt = -1
            else:
                cnt += ai
        else:
            seifu += abs(cnt) +1
            cnt = -1

print(min(fusei, seifu))