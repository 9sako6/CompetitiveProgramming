y, m, d = list(map(int, input().split('/')))
if y < 2019:
    print('Heisei')
elif y == 2019 and m <= 4:
    print('Heisei')
elif m >= 5:
    print('TBD')
