import math

a, b = map(int, input().split())

ab = int(str(a)+str(b))

print('Yes' if math.sqrt(ab) - int(math.sqrt(ab)) == 0 else 'No')


