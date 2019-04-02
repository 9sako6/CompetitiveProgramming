n = gets.to_i
if n == 2 || n == 1
  puts 0
  exit
elsif n == 3
  puts 1
  exit
end
a1 = 0
a2 = 0
a3 = 1

(n - 3).times do
  tmp = a3 + a2 + a1
  tmp %= 10007
  a1 = a2
  a2 = a3
  a3 = tmp
end

p a3
