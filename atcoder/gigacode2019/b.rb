def ok?(a, b)
  return a + b >= Z && a >= X && b >= Y
end
n, X, Y, Z = gets.split.map(&:to_i)
ans = 0
n.times do
  a, b = gets.split.map(&:to_i)
  ans += 1 if ok?(a, b)
end
p ans