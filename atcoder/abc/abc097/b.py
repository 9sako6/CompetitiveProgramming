x = int(input())

maxnum = 0
for j in range(2, 11):
    for i in range(1, x+1):
        if i**j <= x:
            maxnum = i**j if i**j >= maxnum else maxnum
 
print(maxnum)
