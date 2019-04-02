d = gets.to_i
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
sum = 0
ans = Float::INFINITY
d.times do |i|
  sum += a[i]
  ans = [ans, b[i]].min if sum >= b[i]
end
p ans == Float::INFINITY ? -1 : ans