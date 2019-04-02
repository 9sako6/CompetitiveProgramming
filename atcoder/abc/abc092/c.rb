N=gets.to_i
a = gets.split.map(&:to_i) + [0]
all_cost = a[0].abs
N.times do |i|
  all_cost += (a[i] - a[i+1]).abs
end
ans = []
N.times do |i|
  ans << all_cost + (a[i-1] - a[i+1]).abs - (a[i]-a[i-1]).abs - (a[i]-a[i+1]).abs
end
puts ans
  