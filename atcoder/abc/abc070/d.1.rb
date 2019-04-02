N=gets.to_i
g=Array.new(N){[]}
(N-1).times do
  a,b,c = gets.split.map(&:to_i)
  g[a-1] << [b-1, c]
  g[b-1] << [a-1, c]
end

Q,K = gets.split.map(&:to_i)
stack = []
stack << [K-1, 0] # start, depth
depth = Array.new(N,-1) # depth from K-1
while !stack.empty?
  s, d = stack.pop
  depth[s] = d
  g[s].each do |(to, cost)|
    stack << [to, d+cost] if depth[to] == -1
  end
end
ans = []
Q.times do
  x,y = gets.split.map(&:to_i)
  ans << depth[x-1]+depth[y-1]
end
puts ans