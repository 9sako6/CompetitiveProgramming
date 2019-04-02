n, m = gets.split.map(&:to_i)
s = ((n * 60 + m) / 2.0) % 360
l = 6 * m
x, y = [s, l].minmax
if y - x > 180
  p 360 - (y - x)
else
  p y - x
end
