n, m, q = gets.split.map(&:to_i)

g = Array.new(n) { [] }

m.times do
  u, v = gets.split.map(&:to_i)
  u -= 1
  v -= 1
  g[u] << v
  g[v] << u
end
colors = gets.split.map(&:to_i)
ans = []
q.times do
  s = gets.split.map(&:to_i)
  x = s[1] - 1
  if s[0] == 1
    ans << colors[x]
    g[x].each do |v|
      colors[v] = colors[x]
    end
  else
    ans << colors[x]
    colors[x] = s[2]
  end
end
puts ans
