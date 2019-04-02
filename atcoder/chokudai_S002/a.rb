N=gets.to_i
ans = []
N.times do
  a,b = gets.split.map(&:to_i)
  ans << a*b
end
puts ans