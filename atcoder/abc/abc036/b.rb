n = gets.to_i
s = n.times.map { gets.chomp.chars }
t = Array.new(n) { Array.new(n) }
n.times do |i|
  n.times do |j|
    t[j][n - 1 - i] = s[i][j]
  end
end
puts t.map! { |row| row.join("") }
