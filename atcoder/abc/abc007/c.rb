# frozen_string_literal: true

R, C = gets.split.map(&:to_i)
sy, sx = gets.split.map(&:to_i).map { |t| t - 1 }
gy, gx = gets.split.map(&:to_i).map { |t| t - 1 }
c = R.times.map { gets.chomp }

bfs_map = Array.new(R) { Array.new(C, Float::INFINITY) }
bfs_map[sy][sx] = 0
q = []
q << [sy, sx, 0]
d = [[0, 1], [0, -1], [1, 0], [-1, 0]]
until q.empty?
  y, x, dist = q.shift
  d.each do |dy, dx|
    ny = y + dy
    nx = x + dx
    next unless nx >= 0 && nx < C && ny >= 0 && ny < R && c[ny][nx] != '#'

    if bfs_map[ny][nx] > dist + 1
      bfs_map[ny][nx] = dist + 1
      q << [ny, nx, dist + 1]
    end
  end
end
p bfs_map[gy][gx]
