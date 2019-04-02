w, h= gets.split.map(&:to_i)
if 4*h == 3*w
  puts "4:3"
else
  puts "16:9"
end