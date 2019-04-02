arr = list(map(int, input().split()))
k = int(input())
arr.sort()
print(arr[0] + arr[1] + arr[2]*(2**k))

