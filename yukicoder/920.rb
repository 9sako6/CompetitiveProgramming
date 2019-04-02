a = gets.split.map(&:to_i)
d = (a[0] - a[1]).abs
if a[2] >= d
  puts a.inject(&:+) / 2
else
  mn = a[0,2].min
  # p mn
  puts mn + a[2]
end
