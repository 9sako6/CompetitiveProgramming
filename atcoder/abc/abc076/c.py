s=input()
t=input()
index = -999999
for i in range(len(s)):
    if s[i] == t[0]:
        if len(s[i:i+len(t)]) != len(t):
            continue
        for j in range(len(t)):
            if s[i+j] == t[j] or s[i+j] == '?':
                pass
            else:
                break
        index = i
if index == -9999999:
    print('UNRESTORABLE')
    exit()
ans = s[:index] + t + s[index+len(t):]
print(ans.replace('?', 'a'))

