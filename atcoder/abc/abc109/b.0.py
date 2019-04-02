n = int(input())

lastch = ''
answer = 'Yes'
words = []
for i in range(n):
    word = list(input())
    words.append(''.join(word))
    if lastch != word[0] and i != 0:
        answer = 'No'
    lastch = word[-1]

if len(set(words)) != len(words):
    answer = 'No'

print(answer)
