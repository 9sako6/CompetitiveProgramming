r, c, k = gets.split.map(&:to_i)
s = r.times.map { gets.chomp }

d = Array.new(r) { Array.new(c, 1_000_000) }
q = []
r.times do |i|
  c.times do |j|
    if s[i][j] == "x"
      q << [i, j, 0]
      d[i][j] = 0
    end
  end
end

dd = [0, 1, -1]

until q.empty?
  i, j, dist = q.shift
  dd.each do |di|
    dd.each do |dj|
      next if di + dj == 0
      ni = di + i
      nj = dj + j
      if 0 <= ni && ni < r && 0 <= nj && nj < c
        if d[ni][nj] > dist + (di.abs + dj.abs)
          d[ni][nj] = dist + (di.abs + dj.abs)
          q << [ni, nj, dist + (di.abs + dj.abs)]
        end
      end
    end
  end
end
ans = 0
((k-1)..(r - k)).each do |x|
  ((k-1)..(c - k)).each do |y|
    if d[x][y] >= k
      ans += 1
    end
  end
end
p ans