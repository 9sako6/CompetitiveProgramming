n = gets.to_i
ans = Array.new(n) { Array.new(n, 0) }
n.times do
  u, k, *v = gets.split.map(&:to_i)
  u -= 1
  v.each do |vi|
    vi -= 1
    ans[u][vi] = 1
    # ans[vi][u] = 1
  end
end

puts ans.map { |vs| vs * " " }
