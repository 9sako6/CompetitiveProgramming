a, b, m = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
x, y, c = m.times.map { gets.split.map(&:to_i) }.transpose

ans = Float::INFINITY

m.times do |i|
  s = a[x[i] - 1] + b[y[i] - 1] - c[i]
  ans = s if s < ans
end
am = a.min
bm = b.min
ans = am + bm if am + bm < ans
p ans
