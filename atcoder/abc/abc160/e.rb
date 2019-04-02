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

x, y, a, b, c = gets.split.map(&:to_i)
oa = gets.split.map(&:to_i).sort.reverse
ob = gets.split.map(&:to_i).sort.reverse
oc = gets.split.map(&:to_i).sort.reverse

q1 = PriorityQueue.new { |x, y| x > y }
oa[0...x].map { |i| q1.push(i) }
ob[0...y].map { |i| q1.push(i) }

q2 = PriorityQueue.new { |x, y| x > y }
oc.map { |i| q2.push(i) }

ans = 0

(x + y).times do |_|
  if q2.empty?
    ans += q1.pop
  else
    if q2.get > q1.get
      ans += q2.pop
    else
      ans += q1.pop
    end
  end
end
p ans
