n, x, y = gets.split.map(&:to_i)
x -= 1
y -= 1
ans = Hash.new(0)
n.times do |s|
  bfs_map = Array.new(n, 2000)
  bfs_map[s] = 0
  q = [[s, 0]]
  until q.empty?
    v, d = q.shift
    if v != n - 1 && bfs_map[v + 1] > d + 1
      bfs_map[v + 1] = d + 1
      q << [v + 1, d + 1]
    end
    if v != 0 && bfs_map[v - 1] > d + 1
      bfs_map[v - 1] = d + 1
      q << [v - 1, d + 1]
    end
    if v == x && bfs_map[y] > d + 1
      bfs_map[y] = d + 1
      q << [y, d + 1]
    end
    if v == y && bfs_map[x] > d + 1
      bfs_map[x] = d + 1
      q << [x, d + 1]
    end
  end
  bfs_map.each do |d|
    ans[d] += 1
  end
end

1.upto(n - 1) do |k|
  p ans[k] / 2
end
