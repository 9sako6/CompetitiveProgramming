class PriorityQueue
  def initialize(&comp)
    @heap = []
    @node_num = 0
    @comp = if !block_given?
              proc { |x, y| x <= y }
            else
              comp
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

  alias << push

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
    ret
  end

  def get
    @node_num == 0 ? nil : @heap[0]
  end

  def empty?
    get.nil?
  end
end

n, q = gets.split.map(&:to_i)

deleted = Array.new(200_000) { {} }
child = Struct.new('Child', :id, :rate, :kinda)
kinda_pq = Array.new(200_000) { PriorityQueue.new { |x, y| x.rate > y.rate } }
equal_pq = PriorityQueue.new { |x, y| x.rate < y.rate }
children = []

n.times do |i|
  a, b = gets.split.map(&:to_i)
  c = child.new(i, a, b - 1)
  kinda_pq[b - 1] << c
  children << c
end

kinda_pq.each do |pq|
  next if pq.empty?

  equal_pq << pq.get
end

ans = []
q.times do
  e, f = gets.split.map(&:to_i)
  e -= 1
  f -= 1
  c = children[e]
  # c が 最大レートマンだったら
  if c.id == kinda_pq[c.kinda].get&.id
    kinda_pq[c.kinda].pop
    while !(c_next = kinda_pq[c.kinda].get).nil? && deleted[c.kinda][c_next.id]
      kinda_pq[c.kinda].pop
    end
    equal_pq << c_next if c_next
  end
  equal_pq.pop if c.id == equal_pq.get.id
  deleted[c.kinda][c.id] = true
  c.kinda = f
  equal_pq.pop if kinda_pq[f].get && equal_pq.get.id == kinda_pq[f].get.id
  kinda_pq[f] << c
  deleted[c.kinda][c.id] = false
  equal_pq << kinda_pq[f].get
  ans << equal_pq.get.rate
end

puts ans
