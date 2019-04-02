H,W = gets.split.map(&:to_i)
a = []
H.times do
  a << gets.split.map(&:to_i)
end
N = gets.to_i
t = []
N.times do
  t << gets.split.map(&:to_i)
end
puts "---"
p a
puts "---"
t.each do |arr|
  x0, y0, x1, y1 = arr.map{|i| i - 1}
  a[x0][y0] -= 1
  a[x1][y1] += 1
end

p a 
