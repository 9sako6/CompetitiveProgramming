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

N, M = gets.split.map(&:to_i)
p = gets.split.map(&:to_i)
uf = UnionFindWithRank.new(N)
M.times do
  x,y = gets.split.map(&:to_i).map{|e| e-1}
  uf.merge(p[x]-1,p[y]-1)
end
ans = 0
N.times do |i|
  ans += 1 if uf.same?(i, p[i]-1)
end
puts ans