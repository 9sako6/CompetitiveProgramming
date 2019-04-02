H,W = gets.split.map(&:to_i)
cnt = 0 # num of '.'
field = []
H.times do
  l = gets.chomp
  field << l
  cnt += l.count('.')
end

q = []
q << [0,0,1]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
checked = Array.new(H) { Array.new(W, false) }
leng = -1
while !q.empty?
  x,y,d = q.shift
  checked[y][x] = true
  if x == W-1 && y == H-1
    leng = d
    break
  end
  4.times do |i|
    nx = x + dx[i]
    ny = y + dy[i]
    if 0 <= nx && nx < W && 0 <= ny && ny < H && field[ny][nx]=='.' && !checked[ny][nx]
      q << [nx, ny, d+1]
      checked[ny][nx] = true
    end
  end
end
puts leng > 0 ? cnt - leng : -1



