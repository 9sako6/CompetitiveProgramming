n = gets.to_i
s = n.times.map { gets.chomp }
p s.map { |a| a.count("x") }.inject(&:+) + s.map(&:chars).transpose.map { |arr| arr.join("").gsub(/o+/, "@").count("@") }.inject(&:+)
