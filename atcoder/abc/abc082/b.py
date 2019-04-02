s = list(input())
t = list(input())

s.sort()
t.sort(reverse=True)

ss = ''.join(s)
tt = ''.join(t)

print('Yes' if ss < tt else 'No')