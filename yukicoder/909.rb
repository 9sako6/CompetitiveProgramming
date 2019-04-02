n = gets.to_i
x = gets.split.map(&:to_i)
y = gets.split.map(&:to_i)
d = Float::INFINITY
n.times do |i|
  d = [d, x[i] + y[i]].min
end

pos = [0]
n.times do |i|
  pos << (d <= x[i] ? d : x[i])
end
pos << d
puts d
puts pos
