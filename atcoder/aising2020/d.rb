n = gets.to_i
x = gets.chomp
popcount = x.count('1')
x = '0' * (n - x.size) + x if x.size < n
x_lower = popcount > 1 ? x.to_i(2) % (popcount - 1) : -1
x_more = x.to_i(2) % (popcount + 1)

n.times do |i|
  if x[i] == '1' && x_lower == -1
    puts 0
    next
  end
  y = if x[i] == '1'
        (x_lower - 2.pow((n - 1 - i), popcount - 1)) % (popcount - 1)
      else
        (x_more + 2.pow((n - 1 - i), popcount + 1)) % (popcount + 1)
      end
  ans = 1
  while y > 0
    y %= y.to_s(2).count('1')
    ans += 1
  end
  puts ans
end
