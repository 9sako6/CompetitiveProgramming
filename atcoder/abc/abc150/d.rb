n, m = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
ans = 0
b = a.map{|ai| ai / 2}
# 1 <= x <= m
# a.inject(&:)

l = b[0]
b.each do |bi|
  l = l * bi / l.gcd(bi)
end
p l # xの最小値
if l > m
  puts 0
  exit
end

p m / l