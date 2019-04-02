require 'set'
N=gets.to_i
ans = Set.new
N.times do
  a,b = gets.split.map(&:to_i)
  a,b = b,a if a > b
  ans << Set.new([a,b])
end

puts ans.size