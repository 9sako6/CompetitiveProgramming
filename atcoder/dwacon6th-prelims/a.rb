n = gets.to_i
s = []
t = []
n.times do
  a, b = gets.split
  t << b.to_i
  s << a
end
# p s
# p t
x = gets.chomp
ans = 0
flag = false
s.each_with_index do |si, i|
  if si == x
    flag = true
  elsif flag
    ans += t[i]
  end
end

p ans