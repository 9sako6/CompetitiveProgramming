r, D, x = gets.split.map(&:to_i)
ans = [x]
(1..10).each do |i|
  ans << ans[i-1]*r - D
end

puts ans[1..-1]