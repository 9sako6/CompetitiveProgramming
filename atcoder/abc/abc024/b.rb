n, t = gets.split.map(&:to_i)
a = []
n.times do
  a << gets.to_i
end

prev = a[0]
ans = t
(1...n).each do |i|
  if a[i] - prev < t
    ans -= (prev + t) - a[i]
    ans += t
    prev = a[i]
  else
    ans += t
    prev = a[i]
  end
end

p ans
