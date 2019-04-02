s=input()
if int(s[0]+s[1]) <= 12 and int(s[2]+s[3]) <= 12:
    if int(s[0]+s[1]) == 0 and int(s[2]+s[3]) != 0:
        print('YYMM')
    elif int(s[2]+s[3]) == 0 and int(s[0]+s[1]) != 0:
        print('MMYY')
    else:
        if int(s[0]+s[1]) == 0 and int(s[2]+s[3]) == 0:
            print('NA')
        else:
            print('AMBIGUOUS')
elif int(s[0]+s[1]) <= 12 and int(s[2]+s[3]) > 12:
    print('MMYY' if int(s[0]+s[1]) > 0 else 'NA')
elif int(s[0]+s[1]) > 12 and int(s[2]+s[3]) <= 12:
    print('YYMM' if int(s[2]+s[3]) > 0 else 'NA')
else:
    print('NA')
