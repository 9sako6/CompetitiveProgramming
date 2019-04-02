N = int(input())
a= int(input())
b= int(input())
c= int(input())
d= int(input())
e= int(input())

min_i = -1
min_kazu = 10**20
for i, p in enumerate([a, b, c, d, e]):
    if p < min_kazu:
        min_kazu = p
        min_i = i

nokori = 5-min_i
if N%min_kazu == 0:
    print(4+N//min_kazu)
else:
    print(5+N//min_kazu)
