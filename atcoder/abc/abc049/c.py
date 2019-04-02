S = input()
S = S[::-1]
divide = list(map(lambda phrase:phrase[::-1], ['dream', 'dreamer', 'erase', 'eraser']))

flag = False
i = 0
while i != len(S):
    flag = False # 大事
    for d in divide:
        if S[i:i+len(d)] == d:
            flag = True
            i += len(d)
            break

    if flag == False:
        break

print('YES' if flag else 'NO')
