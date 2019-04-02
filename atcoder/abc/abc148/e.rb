require "prime"

# nが奇数の場合0
m = gets.to_i
n = m + 2

f = Array.new(n + 1, 0)
n.times do |i|
  if i == 1 || i == 0
    f[i] = 1
  else
    f[i] = i * f[i - 2]
  end
end

n.times do |i|
  h = Prime.prime_division(f[i]).to_h
  # puts "f(#{i}): #{f[i]}, (2: #{h[2].to_i}, 5:#{h[5]})"
  puts "f(#{i}): (#{h[2].to_i}, #{h[5].to_i})" if i.even?
end

ans = 0  #m / 10

(1..100).each do |a|
  ans += m / (2 * (5 ** a))
end
p ans
