n = gets.to_i
x, l = n.times.map { gets.split.map(&:to_i) }.transpose
a = []
n.times do |i|
  a << [x[i] - l[i], x[i] + l[i]]
end
a.sort_by! { |ai| ai[1] }

ans = 0
t = -Float::INFINITY
n.times do |i|
  if t <= a[i][0]
    ans += 1
    t = a[i][1]
  end
end
p ans
