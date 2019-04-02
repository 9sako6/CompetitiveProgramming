a, b, k = gets.split.map(&:to_i)
if k > a
  puts [0, [0, b - (k - a)].max] * " "
else
  puts [a - k, b] * " "
end
