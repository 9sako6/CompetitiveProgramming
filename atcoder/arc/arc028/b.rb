# frozen_string_literal: true

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

q = PriorityQueue.new { |a, b| a > b }

n, k = gets.split.map(&:to_i)
x = gets.split.map(&:to_i)
m = {}
n.times { |i| m[x[i]] = i + 1 }
k.times do |i|
  q << x[i]
end
(k...n).each do |i|
  if q.get > x[i]
    p m[q.pop]
    q << x[i]
  else
    p m[q.get]
  end
end
p m[q.pop]
