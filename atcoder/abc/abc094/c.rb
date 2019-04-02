n = gets.to_i
x_list = gets.split.map(&:to_i)
x_sorted = x_list.sort()
left, right = x_sorted[n/2-1], x_sorted[n/2]
x_list.each_with_index do |x, i|
  puts (x <= left) ? right : left
end