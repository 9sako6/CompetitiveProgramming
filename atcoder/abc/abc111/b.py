n = int(input())


for _ in range(n, 1000):
    if len(set(list(str(n)))) == 1:
        print(n)
        exit()
    n += 1


