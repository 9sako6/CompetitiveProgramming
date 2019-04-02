cnt = 1
a, b = gets.split.map(&:to_i)
ans = 0
while cnt < b
  cnt -= 1
  cnt += a
  ans += 1
end
p ans