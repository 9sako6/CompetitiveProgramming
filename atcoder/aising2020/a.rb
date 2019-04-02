ans = 0
l, r, d = gets.split.map(&:to_i)
l.upto(r) do |i|
  if i % d == 0
    ans += 1
  end
end
p ans
