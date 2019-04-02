H,W=map(int, input().split())
S=[list(input()) for _ in range(H)]
exS = [['.']*(W+2)]
for s in S:
    exS.append(['.']+s+['.'])
exS.append(['.']*(W+2))

for i in range(1, H+1):
    for j in range(1, W+1):
        if exS[i][j]=='#':
            continue
        else:
            exS[i][j] = str((exS[i][j-1]+exS[i][j+1]\
                      +exS[i-1][j-1]+exS[i-1][j+1]+exS[i-1][j]\
                      +exS[i+1][j-1]+exS[i+1][j+1]+exS[i+1][j]).count('#'))

def show(arr):
    text = ''
    for i in range(1, len(arr)-1):
        if i == 0:
            continue
        elif i == len(arr)-2:
            text += ''.join(arr[i][1:-1])
        else:
            text += ''.join(arr[i][1:-1]) + '\n'
    return text

print(show(exS))