n = gets.to_i
d = n.times.map { gets.to_i }
p m = d.inject(&:+)
p [2 * d.max - m, 0].max
