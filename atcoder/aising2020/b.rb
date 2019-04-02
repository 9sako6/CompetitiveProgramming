n = gets.to_i
a = gets.split.map(&:to_i)
ans = 0
n.times do |i|
  j = i + 1
  if j.odd? && a[i].odd?
    ans += 1
  end
end
p ans
