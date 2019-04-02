n, a, b = gets.split.map(&:to_i)
ans = (n / (a + b)) * a
t = n % (a + b)
if t >= a
  ans += a
else
  ans += t
end
puts ans
