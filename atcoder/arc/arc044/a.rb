require "prime"
n = gets.to_i
if n.prime?
  puts "Prime"
elsif n == 1
  puts "Not Prime"
elsif n.odd? && n % 5 != 0 && n.to_s.chars.map(&:to_i).inject(&:+) % 3 != 0
  puts "Prime"
else
  puts "Not Prime"
end