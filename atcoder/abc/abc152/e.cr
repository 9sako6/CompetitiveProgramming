#read_line.split.map(&.to_i64)
n = read_line.to_i64
a = read_line.split.map(&.to_i64)
mod = 10**9 + 7

l = 1.to_i64
a.each do |ai|
  l = l.lcm(ai)
end

ans = 0.to_i64
a.each do |ai|
  ans += l / ai
  ans %= mod
end

p ans
