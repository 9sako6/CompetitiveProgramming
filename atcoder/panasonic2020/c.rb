a, b, c = gets.split.map(&:to_i)
if 4 * a * b < (c - a - b) * (c - a - b)
  puts (c - a - b) < 0 ? "No" : "Yes"
else
  puts "No"
end
