N,K=gets.split.map(&:to_i)
a=gets.split.map(&:to_i)
s,t,sum=0,0,0
ans = 0
while true
  tmp = 0
  while t < N && sum < K
    sum += a[t]
    t += 1
  end
  break if sum < K
  sum -= a[s]
  s += 1
  ans +=N-t+1
end

p ans