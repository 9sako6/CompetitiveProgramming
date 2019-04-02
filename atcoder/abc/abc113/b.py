n = int(input())
t, a = list(map(int, input().split()))
H = list(map(int, input().split()))

I = 999999
minT = 999999
def temp(x):
    return t - x*0.006

def cal_temp(x):
    return lambda h: x - 0.006 * h

temp = cal_temp(t)

for i in range(n):
    if minT >= abs(a - temp(H[i])):
        minT =  abs(a - temp(H[i]))
        I = i+1

print(I)
