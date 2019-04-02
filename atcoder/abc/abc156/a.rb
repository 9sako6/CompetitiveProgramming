n,r = gets.split.map(&:to_i)
if n >= 10
  puts r
else
  puts r + (10-n)*100
end