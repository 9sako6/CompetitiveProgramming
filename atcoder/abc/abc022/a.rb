n, s, t = gets.split.map(&:to_i)
w = gets.to_i
ans = 0
if s <= w && w <= t
  ans += 1
end
(n-1).times do |i|
  a = gets.to_i
  w += a
  if s <= w && w <= t
    ans += 1
  end
end
p ans
