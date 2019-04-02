N=gets.to_i
a = gets.split.map(&:to_i)
s = Array.new(N+1, 0)
N.times do |i|
  s[i+1] = s[i] + a[i]
end

ans = 10**10
(0...(N-1)).each do |i|
  x = s[i+1] - s[0]
  y = s[N] - s[i+1]
  ans = [ans, (x-y).abs].min
end

puts ans