N=int(input())
sn=sum(list(map(int, list(str(N)))))
print('Yes' if N%sn==0 else 'No')