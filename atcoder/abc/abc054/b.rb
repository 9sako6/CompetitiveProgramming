n, m = gets.split.map(&:to_i)
a = n.times.map { gets.chomp }
b = m.times.map { gets.chomp }
ans = 0
(0..(n - m)).each do |i|
  (0..(n - m)).each do |j|
    flag = true
    m.times do |k|
      flag = false if a[i + k][j, m] != b[k]
    end
    ans += 1 if flag
  end
end

puts ans > 0 ? "Yes" : "No"
