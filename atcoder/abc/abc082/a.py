ab = list(map(int, input().split()))

if int(sum(ab)/2) < (sum(ab))/2:
    print( int(sum(ab)/2)+1)
else:
    print( int(sum(ab)/2))
