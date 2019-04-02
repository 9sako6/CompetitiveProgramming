N, K = map(int, input().split())
S = input()
import re

if len(S) == 1:
    print(1)
    exit()

def renzoku(string, char):
    t = sorted(re.findall(r'{}+'.format(char), string), key=lambda x: -len(x))
    ret = '0'*len(t[0]) if char == '1' else '1'*len(t[0])
    return string.replace(t[0], ret, 1)
S1 = S
for i in range(1, K+1):
    if i % 2 == 0:
        S = renzoku(S, '1')
    else:
        S = renzoku(S, '0')

print(len(sorted(re.findall(r'{}+'.format(1), S), key=lambda x: -len(x))[0]))

for i in range(1, K+1):
    S1 = renzoku(S1, '0')
    print(S1)

print(len(sorted(re.findall(r'{}+'.format(1), S1), key=lambda x: -len(x))[0]))