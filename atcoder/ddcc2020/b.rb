n = gets.to_i
as = gets.split.map(&:to_i)
sum = [tmp = 0].concat(as.map{|a| tmp += a})
diff = Float::INFINITY
n.times do |i|
  next if i == 0
  l = sum[i]
  r = sum[n] - sum[i]
  t = (l - r).abs
  diff = t if diff > t
end
p diff