# 20ぷんくらいかかったし、1WAしてAC。しかももっといい書き方あるよ
s = input()
if s.count('B') == 0 or s.count('W') == 0:
    print(0)
    exit()

import re
if s[0] == 'B':
    s = re.sub(r'B+', 'B', s)
    s = re.sub(r'W+', 'W', s)
    ans = s.count('BW')*2-1
    print(ans if s[-1] != 'B' else ans+1)
else:
    s = re.sub(r'B+', 'B', s)
    s = re.sub(r'W+', 'W', s)
    ans = s.count('WB')*2-1
    print(ans if s[-1] != 'W' else ans+1)