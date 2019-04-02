
#
# 計算量
# - ヒープ作成: O(N)
# - push: O(log N)
# - pop: O(log N)
# - get: O(1)
#
# 最大値を取り出すheapを作る場合は、
# 追加する値の符号を反転しておけばいい
#
class PriorityQueue
  def initialize
    @heap = []
    @node_num = 0
  end

  def push(x)
    i = @node_num # 自分のノード番号
    @node_num += 1
    while i > 0
      par = (i - 1) / 2 # 親のノード番号
      break if @heap[par] <= x # 逆転してないなら抜ける
      # 親ノードを下ろして自分を上に
      @heap[i] = @heap[par]
      i = par
    end
    @heap[i] = x
  end

  def pop()
    # 最小値
    ret = @heap[0]
    # 根にもってくる値
    @node_num -= 1
    x = @heap[@node_num]
    # 根から下ろしていく
    i = 0
    while i * 2 + 1 < @node_num
      # 子どうしを比較
      a, b = i * 2 + 1, i * 2 + 2
      a = b if b < @node_num && @heap[b] < @heap[a]
      break if @heap[a] >= x
      @heap[i] = @heap[a]
      i = a
    end
    @heap[i] = x
    return ret
  end

  def get()
    @heap[0]
  end
end

q = PriorityQueue.new