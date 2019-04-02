c1 = list(input())
c2 = list(input())
print('YES' if c1[0] == c2[-1] and c1[-1] == c2[0] and c1[1] == c2[1] else 'NO')
