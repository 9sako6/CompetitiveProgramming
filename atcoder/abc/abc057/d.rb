com = Array.new(55) { Array.new(55, 0) }
com[0][0] = 1
(1...55).each do |i|
  (i + 1).times do |j|
    com[i][j] += com[i - 1][j]
    com[i][j] += com[i - 1][j - 1] if j > 0
  end
end

n, a, b = gets.split.map(&:to_i)
v = gets.split.map(&:to_f)
v.sort_by! { |vi| -vi }
avg = v[0...a].inject(&:+) / a
cnt = ans = 0
n.times do |i|
  cnt += 1 if v[i] == v[a-1]
end
if v[0] == v[a-1]
  (a..b).each do |j|
    ans += com[cnt][j]
  end
else
  t = 0
  a.times do |j|
    t += 1 if v[j] == v[a-1]
  end
  ans = com[cnt][t]
end
puts sprintf("%.10f\n", avg)
puts ans
