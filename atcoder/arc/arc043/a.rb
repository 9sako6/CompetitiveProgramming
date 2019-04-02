n, a, b = gets.split.map(&:to_i)
s = []
n.times do
  s << gets.to_i
end
mn, mx = s.minmax
if (mx - mn) == 0
  puts -1
  exit
end

x = b.to_f / (mx - mn)
puts [x, a - s.inject(0) { |memo, si| memo + si * x } / n.to_f] * " "
