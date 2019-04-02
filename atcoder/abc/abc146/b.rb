n = gets.to_i
s = gets.chomp
ans = []
s.chars do |c|
  t = c.ord
  ans << ((((t - "A".ord) + n)% 26) + "A".ord).chr
end
puts ans * ""