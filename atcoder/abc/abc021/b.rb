n = gets.to_i
ab = gets.split.map(&:to_i)
m = gets.to_i
a = gets.split.map(&:to_i).concat(ab)
if a.size == a.uniq.size
  puts "YES"
else
  puts "NO"
end