s = input()
import re
sarr = re.split('[^ACTG]', s)
sarr = sorted(sarr, key=lambda x: len(x))
print(len(sarr[-1]))