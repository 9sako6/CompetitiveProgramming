n, a, b = gets.split.map(&:to_i)
ans = 0
1.upto(n) do |i|
  s = i.to_s.split("").map(&:to_i).inject(&:+)
  ans += i if a <= s && s <= b
end
p ans