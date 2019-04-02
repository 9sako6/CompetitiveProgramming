def bfs(s, g)
  bfs_map = Array.new(g.size) { [Float::INFINITY] }
  bfs_map[s] = [0, s]
  q = [[s, 0]]
  until q.empty?
    v, d = q.shift
    g[v].each do |u|
      if bfs_map[u][0] > d + 1
        bfs_map[u][0] = d + 1
        bfs_map[u] << v
        q << [u, d + 1]
      end
    end
  end
  bfs_map
end

n, taka, aoki = gets.split.map(&:to_i)
taka -= 1
aoki -= 1
g = Array.new(n) { [] }
(n - 1).times do
  x, y = gets.split.map(&:to_i)
  x -= 1
  y -= 1
  g[x] << y
  g[y] << x
end

if n == 2
  puts 0
  exit
end

def path_s_to_t(s, t, arr)
  u = s
  path = [s]
  while u != t
    d, from = arr[u]
    path << from
    u = from
  end
  path.reverse
end

da = bfs(aoki, g)
dt = bfs(taka, g)
tmp = da.map { |x| x[0] }
fa = tmp.index(tmp.max) # aokiから一番遠い点
# p da
# p dt
# p fa

pa = path_s_to_t(fa, aoki, da)
pt = path_s_to_t(fa, taka, dt)
ans = 0

prevt = taka
preva = aoki
# p pt
# p pa
if taka == aoki
  puts 0
  exit
end
cntt = 0
cnta = 0
([pa.size, pt.size].max).times do |i|
  next if i == 0
  t = pt[i]
  if t.nil?
    t = pt[cntt.even? ? -2 : -1]
    cntt += 1
  end
  if t == preva
    puts ans
    exit
  end
  # p [t, preva]
  a = pa[i]
  if a.nil?
    a = pa[cnta.even? ? -2 : -1]
    cnta += 1
  end
  ans += 1
  # p [t, a, ans]
  if a == t
    puts ans
    exit
  end
  prevt = t
  preva = a
end
