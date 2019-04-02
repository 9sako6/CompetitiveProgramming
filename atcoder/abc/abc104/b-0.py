string = list(input())

def isA(strlist):
    if strlist[0] == 'A':
        return True

def isC1(strlist):
    if strlist[2:-1].count('C') == 1:
        return True

def issmall(strlist):
    strlist = strlist[2:-1] + [strlist[1]] + [strlist[-1]]
    strlist.remove('C')
    string = ''.join(strlist)
    if string.islower():
        return True


if isA(string) and isC1(string) and issmall(string):
    print('AC')
else:
    print('WA')

