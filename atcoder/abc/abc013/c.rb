n, h = gets.split.map(&:to_i)
a, b, c, d, e = gets.split.map(&:to_i)
ans = Float::INFINITY
0.upto(n) do |x|
  y = [((n * e - x * e - x * b - h) / (d + e)) + 1, 0].max
  # next if h + x * b + y * d - (n - x - y) * e <= 0
  # next if y < 0
  next if y + x > n
  t = a * x + c * y
  ans = t if ans > t
end
p ans
