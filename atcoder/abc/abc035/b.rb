s = gets.chomp
t = gets.to_i
x, y = 0, 0
x -= s.count("L")
x += s.count("R")
y += s.count("U")
y -= s.count("D")
z = s.count("?")
d = x.abs + y.abs
p t == 1 ? d + z : [d - z, s.size % 2].max
