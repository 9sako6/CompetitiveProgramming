n, m = gets.split.map(&:to_i)
g = Array.new(n) { [] }
m.times do
  u, v = gets.split.map(&:to_i)
  g[u - 1] << v - 1
end

s, t = gets.split.map { |x| x.to_i - 1 }

path = Array.new(n) { Array.new(3, -3) }
path[s][0] = 0
q = [[s, 1]]
until q.empty?
  v, r = q.shift
  g[v].each do |child|
    if path[child][r] == -3
      path[child][r] = path[v][(r - 1) % 3] + 1
      q << [child, (r + 1) % 3]
    end
  end
end

# pp path
p path[t][0] / 3
