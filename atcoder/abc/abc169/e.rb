n = gets.to_i
a, b = n.times.map { gets.split.map(&:to_i) }.transpose.map(&:sort)
puts _ = if n.odd?
  b[n / 2] - a[n / 2] + 1
else
  l = a[n/2-1] + a[n/2]
  r = b[n/2-1] + b[n/2]
  r - l + 1
end
