s=input()
k=int(input())
if sum(list(map(int, s[:k]))) == len(s[:k]):
    print(1)
    exit()

for si in s:
    if si!='1':
        break

print(si)
