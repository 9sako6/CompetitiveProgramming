n = gets.to_i
r = gets.chomp
a = [4, 3, 2, 1, 0]
m = %w(A B C D F)
ans = 0
5.times do |i|
  ans += a[i] * r.count(m[i])
end
p ans.to_f / n
