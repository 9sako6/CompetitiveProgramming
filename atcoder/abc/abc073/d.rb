N, M, R = gets.split.map(&:to_i)
r = gets.split.map(&:to_i).map { |x| x - 1 }

# ワーシャルフロイド
MAX = 1<<30
dist = Array.new(N){Array.new(N, MAX)}
M.times do
  a, b, c = gets.split.map(&:to_i)
  dist[a-1][b-1] = dist[b-1][a-1] = c
end

N.times do |k|
  N.times do |i|
    N.times do |j|
      dist[i][j] = dist[i][k]+dist[k][j] if dist[i][j] > dist[i][k]+dist[k][j]
    end
  end
end

ans = r.permutation.map do |perm|
  perm.each_cons(2).inject(0){|sum, (x,y)| sum+dist[x][y]}
end.min
puts ans