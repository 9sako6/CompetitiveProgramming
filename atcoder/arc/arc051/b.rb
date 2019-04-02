k = gets.to_i
t = 0
ans = [[1, 0], [1, 1]]
while t <= 50
  a = ans[-1].inject(&:+)
  b = ans[-1][0]
  ans << [a, b]
  t += 1
end
# p ans
puts ans[k + 1] * " "
