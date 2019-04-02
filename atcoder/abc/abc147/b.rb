s = gets.chomp
if s.size.odd?
  s = s[0...(s.size / 2)] + s[s.size / 2 + 1...s.size]
end
ans = 0
(s.size / 2).times do |i|
  ans += 1 if s[i] != s[s.size - 1 - i]
end
p ans