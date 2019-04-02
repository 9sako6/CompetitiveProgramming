a, b, x = gets.split.map(&:to_f)
s = 2.0 * x / (b * a)
if s > a
  p Math.atan(2.0 * (b * a * a - x) / (a * a * a)) * 180 / Math::PI
else
  p Math.atan(b * b * a / (2.0 * x)) * 180 / Math::PI
end
