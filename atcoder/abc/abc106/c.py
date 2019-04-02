s=input()
k=int(input())
if len(s) >= k and sum(list(map(int, s[:k]))) == len(s[:k]):
    print(1)
    exit()
for si in s:
    if int(si) > 1:
        print(si)
        exit()