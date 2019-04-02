

class PriorityQueue
  def initialize(&comp)
    @heap = []
    @node_num = 0
    if !block_given?
      @comp = lambda { |x, y| x <= y }
    else
      @comp = comp
    end
  end

  def push(x)
    i = @node_num # 自分のノード番号
    @node_num += 1
    while i > 0
      par = (i - 1) / 2 # 親のノード番号
      break if @comp.call(@heap[par], x) # 逆転してないなら抜ける
      # 親ノードを下ろして自分を上に
      @heap[i] = @heap[par]
      i = par
    end
    @heap[i] = x
  end

  alias_method(:<<, :push)

  def pop
    # 最(小|大)値
    ret = @heap[0]
    # 根にもってくる値
    @node_num -= 1
    x = @heap[@node_num]
    # 根から下ろしていく
    i = 0
    while i * 2 + 1 < @node_num
      # 子どうしを比較
      a, b = i * 2 + 1, i * 2 + 2
      a = b if b < @node_num && !@comp.call(@heap[a], @heap[b])
      break if @comp.call(x, @heap[a])
      @heap[i] = @heap[a]
      i = a
    end
    @heap[i] = x
    return ret
  end

  def get
    @node_num == 0 ? nil : @heap[0]
  end

  def empty?
    return get.nil?
  end
end
def dijkstra(graph, start, inf = Float::INFINITY)
  vertex_num = graph.size
  que = PriorityQueue.new { |x, y| x[0] <= y[0] }
  dist = Array.new(vertex_num, inf)
  dist[start] = 0
  que.push([0, start])
  while !que.empty?
    d, v = que.pop
    next if dist[v] < d
    graph[v].size.times do |i|
      # e is an instance of Edge
      #   Edge = Struct.new(:to, :cost)
      e = graph[v][i]
      if dist[e.to] > dist[v] + e.cost
        dist[e.to] = dist[v] + e.cost
        que.push([dist[e.to], e.to])
      end
    end
  end
  return dist
end

n=gets.to_i
g = Array.new(n){[]}
Edge = Struct.new(:to, :cost)
(n-1).times do
  a,b,c = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  g[a] << Edge.new(b, c)
  g[b] << Edge.new(a, c)
end
q,k=gets.split.map(&:to_i)
d = dijkstra(g, k-1)
ans = []
q.times do
  x,y = gets.split.map(&:to_i)
  ans << d[x-1] + d[y-1]
end
puts ans