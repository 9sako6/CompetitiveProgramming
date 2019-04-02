N,M = gets.split.map(&:to_i)
g = []
M.times do
  a,b = gets.split.map(&:to_i)
  g << [a,b]
end
g.sort_by!{|x| x[0]}

cnt = {}
ans = "IMPOSSIBLE"
g.each do |a,b|
  if a == 1
    cnt[b] = true
  elsif b == N && cnt[a]
    ans = "POSSIBLE"
  end
end
puts ans