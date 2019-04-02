m = gets.to_i
if m.odd?
  puts 0
  exit
end
ans = 0
(1..100).each do |a|
  ans += m / (2 * (5 ** a))
end
p ans
