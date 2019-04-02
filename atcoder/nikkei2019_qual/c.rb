n = gets.to_i

k = []
n.times do
  a, b = gets.split.map(&:to_i)
  k << [a, b]
end
k.sort_by! { |a, b| -a - b }
ans = 0
n.times do |i|
  ans += (i.even? ? k[i][0] : -k[i][1])
end
p ans
