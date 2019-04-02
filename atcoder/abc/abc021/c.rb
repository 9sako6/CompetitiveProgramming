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

def dijkstra(graph, start, mod, inf = Float::INFINITY)
  vertex_num = graph.size
  que = PriorityQueue.new { |x, y| x[0] <= y[0] }
  dist = Array.new(vertex_num, inf)
  dist[start] = 0
  num = Array.new(vertex_num, 0) # startから各頂点への最短路数
  num[start] = 1
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
        num[e.to] = num[v]
        que.push([dist[e.to], e.to])
      elsif dist[e.to] == dist[v] + e.cost
        num[e.to] += num[v]
        num[e.to] %= mod
      end
    end
  end
  return [dist, num]
end

mod = 10 ** 9 + 7
n = gets.to_i
a, b = gets.split.map(&:to_i)
a -= 1
b -= 1

g = Array.new(n) { [] }
Edge = Struct.new(:to, :cost)
m = gets.to_i
m.times do
  x, y = gets.split.map(&:to_i)
  x -= 1
  y -= 1
  g[x] << Edge.new(y, 1)
  g[y] << Edge.new(x, 1)
end

p dijkstra(g, a, mod)[1][b]
