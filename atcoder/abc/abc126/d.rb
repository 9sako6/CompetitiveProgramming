N=gets.to_i
g = Array.new(N){[]} 
(N-1).times do |i|
  u,v,w = gets.split.map(&:to_i)
  g[u-1] << [v-1, w]
  g[v-1] << [u-1, w]
  g[u-1] << [u-1, 0]
  g[v-1] << [v-1, 0]
end

stack = []
stack << [0,0]
color = [false]*N
while !stack.empty?
  node, kyori = stack.pop
  color[node] = kyori % 2 == 0 ? 0 : 1
  g[node].each do |edge|
    if !color[edge[0]]
      stack << [edge[0], edge[1]+kyori]
    end
  end
end

puts color
    



