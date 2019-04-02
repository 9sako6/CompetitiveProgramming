n, m = gets.split.map(&:to_i)
a = []
b = []
n.times do
  x, y = gets.split.map(&:to_i)
  a << x
  b << y
end
pin = Array.new(m)
n.times do |i|
  sum = a[i] + b[i]
  if sum <= i
    pin[i-sum] = true
  end
end
puts pin[0...m].compact.size