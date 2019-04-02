x = int(input())
if x < 7:
    print(1)
elif 6 < x < 12:
    print(2)
else:
    if x%11 == 0:
        print((x//11)*2)
    elif x%11 < 7:
        print((x//11)*2 + 1)
    else:
        print((x//11)*2 + 2)