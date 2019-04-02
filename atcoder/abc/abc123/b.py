a= int(input())
b= int(input())
c= int(input())
d= int(input())
e= int(input())

def time(x):
    if x%10 == 0:
        return x
    else:
        return x+(10-x%10)
ans = []
ans.append(time(a)+time(b)+time(c)+time(d)+e)
ans.append(time(a)+time(b)+time(c)+time(e)+d)
ans.append(time(a)+time(b)+time(e)+time(d)+c)
ans.append(time(a)+time(e)+time(c)+time(d)+b)
ans.append(time(e)+time(b)+time(c)+time(d)+a)
print(min(ans))