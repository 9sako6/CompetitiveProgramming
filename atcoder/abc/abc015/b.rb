n = gets.to_i
a = gets.split.map(&:to_i).select{|x| x > 0}
p (a.inject(&:+) + (a.size - 1)) / a.size
