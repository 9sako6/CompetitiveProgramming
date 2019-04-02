x = int(input())
ans, cnt, i = 0, 0, 0
while cnt < x:
    i+=1
    cnt += i
    ans += 1
print(ans)