import numpy as np

n, k = map(int, input().split())
h = list(map(int, input().split()))
print(np.count_nonzero(np.array(h) >= k))
