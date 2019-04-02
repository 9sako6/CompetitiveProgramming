s = list(map(int, list(input())))
minnum = 9999

for i in range(len(s) - 2):
    if minnum > abs(753 - (s[i] * 100 + s[i+1]*10 + s[i+2])):
        minnum = abs(753 - (s[i] * 100 + s[i+1]*10 + s[i+2]))

print(minnum)
