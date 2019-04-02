w, a, b = gets.split.map(&:to_i)
if a + w < b
  puts b - a - w
elsif b + w <= a
  puts a - b - w
else
  puts 0
end
