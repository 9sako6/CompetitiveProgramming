n = gets.to_i
ans = 0
visited = Hash.new(0)
n.times do
  a = gets.to_i
  ans += 1 if visited[a] > 0
  visited[a] += 1
end

p ans
