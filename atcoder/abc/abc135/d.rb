def kakuwa(num)
  num.to_s.split("").inject(0){|sum, c| sum + c.to_i}
end


1000.times do |i|
  puts "#{i}, #{kakuwa(i)}" if i % 13 == 5
end