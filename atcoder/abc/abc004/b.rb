c = 4.times.map{gets.chomp.chars.reverse.join("")}
c.reverse_each do |row|
  puts row
end