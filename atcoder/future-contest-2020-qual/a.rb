n, m, b = gets.split.map(&:to_i)

field = Array.new(n) { Array.new(n, ".") }

gy, gx = gets.split.map(&:to_i)
field[gy][gx] = "G"

m.times do
  y, x, c = gets.split
  field[y.to_i][x.to_i] = c
end
b.times do
  y, x = gets.split.map(&:to_i)
  field[y][x] = "#"
end

# puts field.map{|x| x.join("")}

ans = []

puts ans.size
puts ans
