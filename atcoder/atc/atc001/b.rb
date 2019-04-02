class UnionFindWithRank
  def initialize(n)
    @parent = Array.new(n, -1)
    @rank = Array.new(n, 0)
  end

  def root(x)
    return x if @parent[x] == -1
    @parent[x] = root(@parent[x])
    return @parent[x]
  end

  def same?(x, y)
    return root(x) == root(y)
  end

  def merge(x, y)
    x, y = root(x), root(y)
    return false if x == y
    x, y = y, x if @rank[x] < @rank[y]
    @rank[x] += 1 if @rank[x] == @rank[y]
    @parent[y] = x
    return true
  end
end

N, Q = gets.split.map(&:to_i)
uf = UnionFindWithRank.new(N)
ans = []
Q.times do
  q, a, b = gets.split.map(&:to_i)
  if q == 0
    uf.merge(a-1, b-1)
  else
    ans << (uf.same?(a-1, b-1) ? 'Yes' : 'No')
  end
end
puts ans