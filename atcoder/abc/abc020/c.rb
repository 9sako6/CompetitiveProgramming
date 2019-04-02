D = [[1, 0], [-1, 0], [0, 1], [0, -1]]
MAX = 1e10
def check(m)
  bfs_map = Array.new(H) { Array.new(W, MAX) }
  bfs_map[$start_y][$start_x] = 0
  q = [[$start_y, $start_x, 0]]
  until q.empty?
    y, x, cnt = q.shift
    D.each do |dy, dx|
      ny = dy + y
      nx = dx + x
      if ny >= 0 && ny < H && nx >= 0 && nx < W
        nd = cnt + ($s[ny][nx] == "#" ? m : 1)
        if nd < bfs_map[ny][nx]
          bfs_map[ny][nx] = nd
          q << [ny, nx, nd]
        end
      end
    end
  end
  return bfs_map[$goal_y][$goal_x]
end

H, W, T = gets.split.map(&:to_i)
$s = []
H.times { $s << gets.chomp }

$start_x = 0
$start_y = 0
$goal_x = 0
$goal_y = 0
H.times do |y|
  W.times do |x|
    if $s[y][x] == "S"
      $start_y = y
      $start_x = x
    elsif $s[y][x] == "G"
      $goal_y = y
      $goal_x = x
    end
  end
end

ok = 1
ng = T + 1
while (ok - ng).abs > 1
  mid = (ok + ng) / 2
  if check(mid) <= T
    ok = mid
  else
    ng = mid
  end
end

p ok
