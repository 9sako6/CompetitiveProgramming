import numpy as np
n = int(input())
k = np.arange(1, 10)
print("Yes" if (np.dot(k[:,None] , k[None,:]) == n).sum() else "No")
