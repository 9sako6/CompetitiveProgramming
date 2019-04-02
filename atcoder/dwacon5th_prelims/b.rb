n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
acc = 0
accs = a.map { |ai| acc += ai }.unshift(0)
old = accs.combination(2).map { |x, y| y - x }
# p old
42.downto(0) do |i|
  ne = old.select { |x| x[i] == 1 }
  old = ne if ne.size >= k
end
puts old.inject(&:&)
