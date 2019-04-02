m = int(input())
mkm = m / 1000
if mkm < 0.1:
    print('00')
elif 0.1 <= mkm <= 5:
    mkm *= 10
    if len(list(str(int(mkm)))) == 1:
        print('{:02}'.format(int(mkm)))
    else:
        print(int(mkm))
elif 6 <= mkm <= 30:
    print(int(mkm)+50)
elif 35 <= mkm <= 70:
    print(int((mkm-30) / 5 + 80))
elif 70 < mkm:
    print('89')



