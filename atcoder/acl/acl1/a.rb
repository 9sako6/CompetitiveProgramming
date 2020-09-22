# Disjoint Set Union
class DSU
  def initialize(n = 0)
    # root node: -1 * component size
    # otherwise: parent
    @parent_or_size = Array.new(n) { -1 }
  end

  def merge(a, b)
    x = leader(a)
    y = leader(b)
    return x if x == y

    x, y = y, x if -@parent_or_size[x] < -@parent_or_size[y]
    @parent_or_size[x] += @parent_or_size[y]
    @parent_or_size[y] = x
    x
  end

  def same(a, b)
    leader(a) == leader(b)
  end

  def leader(a)
    @parent_or_size[a] < 0 ? a : (@parent_or_size[a] = leader(@parent_or_size[a]))
  end

  def size(a)
    -@parent_or_size[leader(a)]
  end

  def groups_with_leader
    h = Hash.new { |hash, key| hash[key] = [] }
    @parent_or_size.each_with_index do |parent_or_size, i|
      leader = parent_or_size < 0 ? i : parent_or_size
      h[leader] << i
    end
    h
  end

  def groups
    groups_with_leader.values
  end

  alias root leader
  alias find leader
  alias unite merge
  alias union merge
  alias same? same
end

n = gets.to_i
xy = []
n.times { xy << gets.split.map(&:to_i) }
xy.sort!
dsu = DSU.new(n)

tmp, yfrag = 0, Array.new(n, 0)

xy.each do |x, y|
  p [x, y]
  yfrag[x - 1] = 1
  tmp += yfrag[n - x] + (y > n - x) ? 1 : 0
  dsu.union(x, x - 1) if tmp < x
end

n.times { uf.size()}
