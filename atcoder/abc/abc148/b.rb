n = gets.to_i
s, t = gets.split
ans = ""
n.times do |i|
  ans << s[i]
  ans << t[i]
end
puts ans