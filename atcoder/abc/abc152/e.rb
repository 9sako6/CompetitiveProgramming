n = gets.to_i
a = gets.split.map(&:to_i)
mod = 10**9 + 7

l = 1
a.each do |ai|
  l = l.lcm(ai)
end

ans = 0
a.each do |ai|
  ans += l / ai
end

p ans % mod
