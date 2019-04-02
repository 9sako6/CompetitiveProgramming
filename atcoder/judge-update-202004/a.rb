s, l, r = gets.split.map(&:to_i)
if s < l
  puts l
elsif s > r
  puts r
else
  puts s
end