N=gets.to_i
ans = []
N.times do
  a,b = gets.split.map(&:to_i)
  ans << a.gcd(b)
end

puts ans