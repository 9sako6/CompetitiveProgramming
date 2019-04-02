class PriorityQueue
  def initialize(&comp)
    @heap = []
    @node_num = 0
    if !block_given?
      @comp = Proc.new { |x, y| x <= y }
    else
      @comp = comp
    end
  end

  attr_reader :heap

  def push(x)
    current_node_num = @node_num
    @node_num += 1
    while current_node_num > 0
      parent_node_num = (current_node_num - 1) / 2
      break if @comp.call(@heap[parent_node_num], x) # 逆転してないなら抜ける
      # 親ノードを下ろして自分を上に
      @heap[current_node_num] = @heap[parent_node_num]
      current_node_num = parent_node_num
    end
    @heap[current_node_num] = x
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
    while (a = i * 2 + 1) < @node_num
      # 子どうしを比較
      b = a + 1
      a = b if b < @node_num && @comp.call(@heap[b], @heap[a])
      break unless @comp.call(@heap[a], x)
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

#
# dijkstra
#   O(|E|log|V|)
#   隣接表現グラフgraph, 始点start, inf
#
def dijkstra(graph, start, inf = Float::INFINITY)
  vertex_num = graph.size
  que = PriorityQueue.new { |x, y| x[0] <= y[0] }
  dist = Array.new(vertex_num, inf)
  dist[start] = 0
  que.push([0, start])
  while !que.empty?
    d, v = que.pop
    dist_now = dist[v]
    next if dist_now < d
    graph[v].each do |e|
      # e is an instance of Edge
      #   Edge = Struct.new(:to, :cost)
      # e = graph[v][i]
      if dist[e.to] > dist_now + e.cost
        que.push([dist[e.to] = dist_now + e.cost, e.to])
      end
    end
  end
  return dist
end

Edge = Struct.new(:to, :cost)
n, m = gets.split.map(&:to_i)
g = Array.new(n) { [] }

(n - 2).times do |i|
  g[i + 1] << Edge.new(i, 0)
end

m.times do
  l, r, c = gets.split.map(&:to_i)
  l -= 1
  r -= 1
  g[l] << Edge.new(r, c)
end
ans = dijkstra(g, 0)[n - 1]
puts ans == Float::INFINITY ? -1 : ans
