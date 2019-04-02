n = gets.to_i
a = n.times.map { gets.to_i }
if a[0] != 0
  puts -1
  exit
end
(n - 1).times do |i|
  if a[i + 1] - a[i] >= 2
    puts -1
    exit
  end
end
ans = 0

s = []
prev = -1
cnt = 1
a.each do |ai|
  if prev == ai
    cnt += 1
  else
    s << [prev, cnt]
    cnt = 1
    prev = ai
  end
  ans += 1 if ai != 0
end
s << [prev, cnt]
s.shift
# p s
s.each do |ai, m|
  next if ai == 0 || ai == 1
  ans += (2 ** (ai - 2)) * (m - 1)
end
p ans
