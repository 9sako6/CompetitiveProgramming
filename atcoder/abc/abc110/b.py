cnds = [int(i) for i in input().split()]

posX = [int(i) for i in input().split()]
posY = [int(i) for i in input().split()]
posX.sort()
posY.sort()

max_x = posX[-1]
min_y = posY[0]
if cnds[2] < cnds[3]:
    if max_x < min_y and cnds[2] < min_y and max_x < cnds[3]:
        print('No War')
    else:
        print('War')
else:
    print('War')



