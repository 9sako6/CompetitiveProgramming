n=gets.to_i
s=gets.chomp
t=""
prev=s[0]
(1...n).each do |i|
  if s[i] == prev
    next
  else
    t << prev
    prev = s[i]
  end
end
if t[-1] != prev
  t << prev
end

p t.size