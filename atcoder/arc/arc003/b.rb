n = gets.to_i
s = []
n.times { s << gets.chomp.reverse }
s.sort!
puts s.map { |si| si.reverse }
