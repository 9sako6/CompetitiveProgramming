a, b, c = gets.split.map(&:to_i).sort
if a == b
  puts c
else
  puts a
end