n,k=gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
MOD = 10**9+7
ans = 0
n.times do |i|
  lt = rlt = 0
  n.times do |j|
    lt += 1 if a[j] < a[i]
    rlt += 1 if j > i && a[j] < a[i]
  end
  ans += (k*k - (1+k)*k/2) * lt + k*rlt
  ans %= MOD
end
p ans
  
