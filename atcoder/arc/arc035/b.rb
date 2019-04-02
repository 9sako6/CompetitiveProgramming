n = gets.to_i
a = n.times.map { gets.to_i }.sort
mod = 10 ** 9 + 7
t = 0
sum = 0
cnt = Hash.new(0)
a.each do |ai|
  t += ai
  cnt[ai] += 1
  sum += t
end

MAX = 10000 + 10
fact = Array.new(MAX, 1)
1.upto(MAX - 1) do |i|
  fact[i] = (fact[i - 1] * i) % mod
end

ans = 1

cnt.each do |_, c|
  ans *= fact[c]
  ans %= mod
end
p sum
p ans
