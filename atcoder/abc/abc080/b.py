n = input()
n_list = list(map(int, list(n)))

n = int(n)

print('Yes' if n % sum(n_list) == 0 else 'No')
