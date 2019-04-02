n = gets.to_i
s = gets.chomp
mod = 10 ** 9 + 7
ans = (n + 1) * n / 2
h = {}
"a".upto("z") { |c| h[c] = s.count(c) }
p ans - h.values.select { |x| x > 1 }.inject(&:*).to_i
