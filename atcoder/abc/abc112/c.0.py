N = int(input())
xyh = [list(map(int, input().split())) for i in range(N)]

for cx in range(101):
    for cy in range(101):
        needH = -1

        for x, y, h in xyh:
            if h > 0:
                # この頂点から見て、頂上がcx, cyのときどのくらいの高さがあってほしいか
                tmp = h + abs(cx - x) + abs(cy - y)
                if needH == -1:
                    needH = tmp
                else:
                    if needH != tmp:
                        needH = -2
                        break

        if needH == -2:
            continue

        for x, y, h, in xyh:
            if h == 0:
                dist = abs(cx - x) + abs(cy - y)
                if needH - dist > 0:
                    needH = -2
                    break
        if needH == -2:
            continue

        print(cx, cy, needH)
        exit()
