n = gets.to_i
g = Array.new(n){[]}

edges = Array.new(n-1) # へんの色を格納

(n-1).times do |i|
  a, b = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  g[a] << [b, i]
  g[b] << [a, i]
end

q = []
root = 0
color_num = 0 
g[root].each do |child, i|
  color_num += 1
  q << [child, root, color_num]
  edges[i] = color_num
end

until q.empty?
  now, parent, c = q.shift
  ccnt = 0
  g[now].each do |child, i|
    next if child == parent
    ccnt += 1
    if ccnt == c
      ccnt += 1
    end
    q << [child, now, ccnt]
    edges[i] = ccnt
  end
end

p edges.max
puts edges