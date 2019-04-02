s = gets.chomp
n = gets.to_i
n.times do
  l, r = gets.split.map(&:to_i)
  l -= 1
  r -= 1
  s[l..r] = s[l..r].reverse
end

puts s