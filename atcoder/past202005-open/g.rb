GRID_SIZE = 500
n, x, y = gets.split.map(&:to_i)
x += GRID_SIZE / 2
y += GRID_SIZE / 2
g = Array.new(GRID_SIZE) { Array.new(GRID_SIZE, '.') }

n.times do
  a, b = gets.split.map(&:to_i)
  a += GRID_SIZE / 2
  b += GRID_SIZE / 2
  g[b][a] = '#'
end

bfs_map = Array.new(GRID_SIZE) { Array.new(GRID_SIZE, -1) }

q = [[GRID_SIZE / 2, GRID_SIZE / 2, 0]] # start
dd = [0, 1, -1]
bfs_map[GRID_SIZE / 2][GRID_SIZE / 2] = 0
until q.empty?
  xi, yi, d = q.shift

  dd.each do |dx|
    dd.each do |dy|
      if (dx == 0 && dy == 0) || (dx == -1 && dy == -1) || (dx == 1 && dy == -1)
        next
      end

      nx = xi + dx
      ny = yi + dy
      unless nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE && g[ny][nx] == '.'
        next
      end

      if bfs_map[ny][nx] == -1
        bfs_map[ny][nx] = d + 1
        q << [nx, ny, d + 1]
      end
    end
  end
end
p bfs_map[y][x]

__END__

8 2 2
1 1
1 -1
1 0
0 1
0 -1
-1 -1
-1 1
-1 0

7 2 2
1 1
1 -1
1 0
0 1
0 -1
-1 1
-1 0
