a, b = map(int, input().split())
s = list(input())
ans = 'No'
if s[a] == '-' and s.count('-') == 1:
    print('Yes')
else:
    print('No')


