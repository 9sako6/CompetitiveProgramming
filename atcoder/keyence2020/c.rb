n, k, s = gets.split.map(&:to_i)
ans = []
k.times do
  ans << s
end

# sの約数じゃない数
t = (s == 10 ** 9 ? 7 : 10 ** 9)
(n - k).times do
  ans << t
end

puts ans * " "
