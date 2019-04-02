n = gets.to_i
buka = Array.new(n + 1) { [] }
(2..n).each { |i| buka[gets.to_i] << i }
ans = Array.new(n + 1, 1)
n.downto(1) do |i|
  ans[i] = (buka[i].empty? ? 1 : buka[i].map { |b| ans[b] }.minmax.inject(&:+) + 1)
end
p ans[1]
