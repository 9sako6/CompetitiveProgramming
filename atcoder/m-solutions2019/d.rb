N=gets.to_i
g = Array.new(N){[]}
(N-1).times do
  a,b = gets.split.map(&:to_i)
  g[a-1] << b-1
  g[b-1] << a-1
end
c = gets.split.map(&:to_i)

set_pos = (0...N).to_a
set_pos.sort_by!{|i| g[i].size}
c.sort_by!{|x| -x}
ans = 0

d = Array.new(N) # 書き込むべき整数

used = Array.new(N)
start = set_pos[0]
q = []
q << start

d[start] = c.shift

while !q.empty?
  par = q.shift
  used[par] = true
  g[par].each do |child|
    if !used[child]
      cost = c.shift
      q << child
      ans += cost
      d[child] = cost
    end
  end
end

puts ans
puts d * ' '