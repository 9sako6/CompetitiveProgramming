from collections import defaultdict

def a(s):
    dic = defaultdict(list)
    for i, ch in enumerate(s):
        dic[ch].append(i)
    return sorted(list(dic.values()))

s = input()
t = input()
print('Yes' if a(s) == a(t) else 'No')
