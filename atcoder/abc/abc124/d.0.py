N, K = map(int, input().split())
S = list(map(int, list(input())))
now = 1
cnt = 0
Nums = []
for i in range(N):
    if S[i] == now:
        cnt += 1
    else:
        Nums.append(cnt)
        now = 1 - now
        cnt = 1
if cnt != 0:
    Nums.append(cnt)

if len(Nums) % 2 == 0:
    Nums.append(0)

add = 2*K+1
ans = 0
left, right = 0, 0
tmp = 0  # sum of [left, right)
for i in range(len(Nums))[::2]:
    next_left = i
    next_right = min(i + add, len(Nums))
    while next_left > left:
        tmp -= Nums[left]
        left += 1
    while next_right > right:
        tmp += Nums[right]
        right += 1

    ans = max(tmp, ans)

print(ans)
