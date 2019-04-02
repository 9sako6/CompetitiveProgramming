n, m, _ = gets.split.map(&:to_i)
r = gets.split.map { |z| z.to_i - 1 }
max = 1e10
d = Array.new(n) { Array.new(n, max) }
m.times do
  a, b, c = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  d[a][b] = c
  d[b][a] = c
end
n.times do |k|
  n.times do |i|
    n.times do |j|
      tmp = d[i][k] + d[k][j]
      d[i][j] = tmp if d[i][j] > tmp
    end
  end
end
ans = r.permutation.map do |perm|
  perm.each_cons(2).inject(0) { |sum, (x, y)| sum + d[x][y] }
end.min

p ans
