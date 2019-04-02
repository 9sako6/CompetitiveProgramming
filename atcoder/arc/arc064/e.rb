def dijkstra(graph, start, inf = Float::INFINITY)
  vertex_num = graph.size
  dist = Array.new(vertex_num, inf)
  used = Array.new(vertex_num)
  dist[start] = 0
  loop do
    v = -1
    vertex_num.times do |u|
      v = u if !used[u] && (v == -1 || dist[u] < dist[v])
    end
    break if v == -1
    used[v] = true
    graph[v].each do |e|
      dist[e.to] = dist[v] + e.cost if dist[e.to] > dist[v] + e.cost
    end
  end
  return dist
end

Edge = Struct.new(:to, :cost)
sx, sy, tx, ty = gets.split.map(&:to_i)
n = gets.to_i
g = Array.new(n + 2) { [] }
inputs = n.times.map { gets.split.map(&:to_i) }
inputs << [sx, sy, 0]
inputs << [tx, ty, 0]
(n + 2).times do |i|
  xi, yi, ri = inputs[i]
  (i + 1...n + 2).each do |j|
    xj, yj, rj = inputs[j]
    cost = ((xi - xj) ** 2 + (yi - yj) ** 2) ** 0.5
    cost -= ri + rj
    cost = 0 if cost < 0
    g[i] << Edge.new(j, cost)
    g[j] << Edge.new(i, cost)
  end
end
p dijkstra(g, n)[n + 1]
