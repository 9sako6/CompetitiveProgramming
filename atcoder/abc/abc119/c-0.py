#
# dead
#


n, a, b, c = list(map(int, input().split()))
l = [int(input()) for _ in range(n)]

abc = [a, b, c]

cost = 0
for take in abc:
    if take in l:
        l.remove(take)
        continue
    else:
        temp_cost = 9999999
        for i in range(len(l)):
            temp_cost = min(temp_cost, abs(take - l[i]))



        cost += temp_cost

print(cost)
