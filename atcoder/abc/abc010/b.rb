n = gets.to_i
a = gets.split.map(&:to_i)
#   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
b = [0, 0, 1, 0, 1, 2, 3, 0, 1, 0]
p a.map{|x| b[x]}.inject(&:+)