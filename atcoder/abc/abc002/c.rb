xy = gets.split.map(&:to_i)
(2..5).each do |i|
  if i.even?
    xy[i] -= xy[0]
  else
    xy[i] -= xy[1]
  end
end

puts (xy[2]*xy[5] - xy[3]*xy[4]).abs/2.0