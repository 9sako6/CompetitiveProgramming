n = int(input())

lastch = ''
answer = 'Yes'
words = []

for i in range(n):
    word = input()
    words.append(word)
    if lastch != word[0] and i != 0:
        answer = 'No'
    lastch = word[-1]

if len(words) != len(set(words)):
    answer = 'No'

print(answer)
