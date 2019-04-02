n = gets.to_i
mod = 10**9 + 7
power = 1
n.times do |i|
    power *= i + 1
    power %= mod
end
p power