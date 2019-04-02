a, b, k, l = gets.split.map(&:to_i)
if a * l > b
  p [(k / l) * b + (k % l) * a, (k / l + 1) * b].min
else
  p k * a
end
