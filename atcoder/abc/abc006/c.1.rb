n, m = gets.split.map(&:to_i)
100010.times do |c|
  x = n - c
  y = m - 4 * c
  a = 3 * x - y
  b = y - 2 * x
  if a >= 0 && b >= 0
    puts [a, b, c] * " "
    exit
  end
end
puts [-1, -1, -1] * " "
