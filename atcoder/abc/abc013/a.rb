a = gets.split.map(&:to_i).sort
b = gets.split.map(&:to_i).sort
if [*0..2].all? { |i| a[i] >= b[i] }
  p a.inject(&:*) / b.inject(&:*)
else
  p 0
end
