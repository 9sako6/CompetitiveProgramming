N = gets.to_i
a = gets.split.map(&:to_i)
sum = 0
h = Hash.new(0)
h[0] += 1
a.each do |ai|
  sum += ai
  h[sum] += 1
end
ans = 0
h.each do |i, cnt|
  next if cnt < 2
  ans += (cnt * (cnt - 1)) / 2
end

p ans
