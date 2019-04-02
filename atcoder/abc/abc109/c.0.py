from functools import reduce

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def gcd_list(nums):
    return reduce(gcd, nums)

N, X = list(map(int, input().split()))
x = list(map(int, input().split()))
diff = [abs(xi - X) for xi in x]
print(gcd_list(diff))


