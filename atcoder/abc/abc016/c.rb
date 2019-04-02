n, m = gets.split.map(&:to_i)
g = Array.new(n) { [] }
m.times do
  a, b = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  g[a] << b
  g[b] << a
end

n.times do |node|
  cnt = 0
  fs = g[node]
  yet = Array.new(n, true)
  fs.each do |f|
    g[f].each do |ff|
      cnt += 1 if ff != node && !fs.include?(ff) && yet[ff]
      yet[ff] = false
    end
  end
  puts cnt
end
