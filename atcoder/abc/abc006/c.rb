n, m = gets.split.map(&:to_i)
(10**5+10).times do |i|
  b = 4*n-2*i-m
  c = n-i-b
  if i >= 0 && b >= 0 && c >= 0
    puts [i, b, c] * ' '
    exit
  end
end
puts [-1, -1, -1] *  ' '