R,G,B,N = map(int, input().split())
ans = 0
for r in range(N//R+1):
    for g in range(N//G+1):
        if N-r*R-g*G >= 0 and (N-r*R-g*G) % B == 0:
            ans += 1

print(ans)

