n, k = gets.split.map(&:to_i)
r = gets.split.map(&:to_i)

r.sort!
puts sprintf("%.10f", r[-k..-1].inject(0){|avg, x| (avg+x)/2.0})