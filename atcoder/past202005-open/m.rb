def dist(s)
  q = [[s, 0]]
  bfs_map = Array.new($g.size, Float::INFINITY)
  bfs_map[s] = 0
  until q.empty?
    v, d = q.shift
    $g[v].each do |u|
      if bfs_map[u] > d + 1
        bfs_map[u] = d + 1
        q << [u, d + 1]
      end
    end
  end
  bfs_map
end

n, m = gets.split.map(&:to_i)
$g = Array.new(n) { [] }
m.times do
  u, v = gets.split.map(&:to_i)
  u -= 1
  v -= 1
  $g[u] << v
  $g[v] << u
end
s = gets.to_i - 1
k = gets.to_i

node = {}
node[s] = 0
t = gets.split.map { _1.to_i - 1 }
t.each_with_index { |ti, i| node[ti] = i + 1 }

gn = Array.new(k + 1) { Array.new(k + 1, Float::INFINITY) }

ds = dist(s)
gn[0][0] = 0
t.each do |ti|
  gn[node[s]][node[ti]] = gn[node[ti]][node[s]] = [ds[ti], gn[node[s]][node[ti]]].min
  d = dist(ti)
  t.each do |tj|
    gn[node[ti]][node[tj]] = gn[node[tj]][node[ti]] = [d[tj], gn[node[ti]][node[tj]]].min
  end
end

K = k + 1
dp = Array.new(1 << K) { Array.new(K, Float::INFINITY) }
dp[(1 << K) - 1][0] = 0

(0..((1 << K) - 2)).reverse_each do |state|
  dps = dp[state]
  K.times do |v|
    K.times do |u|
      next if state >> u & 1 == 1
      next if u == v

      dps[v] = [
        dps[v],
        dp[state | (1 << u)][u] + gn[v][u]
      ].min
    end
  end
end
puts dp[0][0]
p dp[0]
p dp[-1]
p gn
# $n = k + 1
# def rec(s, v)
#   dps = $dp[s]
#   return dps[v] if dps[v] >= 0

#   return dps[v] = 0 if s == (1 << $n) - 1

#   res = Float::INFINITY
#   $n.times do |u|
#     res = [res, rec(s | (1 << u), u) + gn[v][u]].min unless (s >> u) & 1 == 1
#   end
#   dps[v] = res
# end

# puts rec(0, node[s])
