class UnionFind
  def initialize(n)
    @parent = (0..n).to_a
  end

  def unite(x, y)
    while @parent[x] != @parent[y]
      x, y = y, x if @parent[x] > @parent[y]
      break @parent[x] = @parent[y] if x == @parent[x]
      @parent[x], x = @parent[y], @parent[x]
    end
  end

  def root(x)
    x = @parent[@parent[x]] while x != @parent[x]
    return x
  end
end

n, k, l = gets.split.map(&:to_i)
uf1 = UnionFind.new(n)
uf2 = UnionFind.new(n)
k.times do
  a, b = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  uf1.unite(a, b)
end
l.times do
  a, b = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  uf2.unite(a, b)
end
cnt = Hash.new(0)
n.times do |i|
  cnt[[uf1.root(i), uf2.root(i)].inspect] += 1
end
ans = []
n.times do |i|
  ans << cnt[[uf1.root(i), uf2.root(i)].inspect]
end
puts ans * " "
