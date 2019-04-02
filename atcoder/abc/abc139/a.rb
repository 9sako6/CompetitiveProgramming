ans = 0
s = gets.chomp
t = gets.chomp
3.times do |i|
  ans += 1 if s[i] == t[i]
end
p ans
