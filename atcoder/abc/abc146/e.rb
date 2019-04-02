n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

s = [tmp = 0].concat(a.map { |ai| tmp += ai })
ans = 0
1.upto(n) do |j|
  [(j-k + 1), 1].max.upto(j-1) do |i|
    ans += 1 if (s[j] - j) % k == (s[i] - i) % k
  end
end

p ans