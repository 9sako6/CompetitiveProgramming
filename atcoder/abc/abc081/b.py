from functools import reduce
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def gcd_list(nums):
    return reduce(gcd, nums)

n = input()
A = list(map(int, input().split()))

gcd_num = gcd_list(A)
ope = 0
while 1:
    if gcd_num % 2 == 0:
        ope += 1
        gcd_num /= 2
    else:
        break
print(ope)