a = gets.to_i
b = gets.to_i
[1, 2, 3].each do |i|
  if i == a || i == b
    next
  else
    p i
  end
end
