def draw(arr)
  puts "--"
  puts arr.map{|row| row.map(&:to_s).join(' ')}
end

N=gets.to_i
field = Array.new(2*N) {Array.new(2*N, '.')}
N.times do
  a,b = gets.split.map(&:to_i)
  field[b][a] = 'R'
end
N.times do
  a,b = gets.split.map(&:to_i)
  field[b][a] = 'B'
end

# cnt[y][x]
cnt_red = Array.new(2*N) {Array.new(2*N, 0)}
(2*N).times do |y|
  (2*N).times do |x|
    if y-1 >= 0 && x-1 >= 0
      cnt_red[y][x] = cnt_red[y-1][x] + cnt_red[y][x-1] - cnt_red[y-1][x-1] + (field[y][x] == 'R' ? 1 : 0)
    elsif y-1 >= 0
      cnt_red[y][x] = cnt_red[y-1][x] + (field[y][x] == 'R' ? 1 : 0)
    elsif x-1 >= 0
      cnt_red[y][x] = cnt_red[y][x-1] + (field[y][x] == 'R' ? 1 : 0)
    else
      cnt_red[y][x] = (field[y][x] == 'R' ? 1 : 0)
    end
  end
end

# cnt[y][x]
cnt_blue = Array.new(2*N) {Array.new(2*N, 0)}
(2*N).times do |y|
  (2*N).times do |x|
    if y-1 >= 0 && x-1 >= 0
      cnt_blue[y][x] = cnt_blue[y-1][x] + cnt_blue[y][x-1] - cnt_blue[y-1][x-1] + (field[y][x] == 'B' ? 1 : 0)
    elsif y-1 >= 0
      cnt_blue[y][x] = cnt_blue[y-1][x] + (field[y][x] == 'B' ? 1 : 0)
    elsif x-1 >= 0
      cnt_blue[y][x] = cnt_blue[y][x-1] + (field[y][x] == 'B' ? 1 : 0)
    else
      cnt_blue[y][x] = (field[y][x] == 'B' ? 1 : 0)
    end
  end
end

ans = Array.new(2*N) {Array.new(2*N, 0)}
(2*N).times do |y|
  (2*N).times do |x|
    if y-1 >= 0 && x-1 >= 0
      ans[y][x] = ans[y-1][x] + ans[y][x-1] - ans[y-1][x-1] + (cnt_blue[y][x] <= cnt_red[y][x] && field[y][x] == 'B' ? 1 : 0)
    elsif y-1 >= 0
      ans[y][x] = ans[y-1][x] + (cnt_blue[y][x] <= cnt_red[y][x] && field[y][x] == 'B' ? 1 : 0)
    elsif x-1 >= 0
      ans[y][x] = ans[y][x-1] + (cnt_blue[y][x] <= cnt_red[y][x] && field[y][x] == 'B' ? 1 : 0)
    else
      ans[y][x] = 0
    end
  end
end
draw(field.reverse)
draw(cnt_red.reverse)
draw(cnt_blue.reverse)
draw(ans.reverse)
puts ans[-1][-1]

