n, m = gets.split.map(&:to_i)
g = Array.new(n) { [] }
m.times do
  u, v = gets.split.map(&:to_i)
  g[u - 1] << v - 1
end
s, t = gets.split.map { |x| x.to_i - 1 }

dist = Array.new(n) { Array.new(3, -3) }
dist[s][0] = 0
q = []
q << [s, 1]
until q.empty?
  from, cnt = q.shift
  g[from].each do |to|
    if dist[to][cnt] == -3
      dist[to][cnt] = dist[from][(cnt - 1) % 3] + 1
      q << [to, (cnt + 1) % 3]
    end
  end
end
p dist[t][0] / 3
