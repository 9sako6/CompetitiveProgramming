N,M = gets.split.map(&:to_i)
cards = Array.new(N+1,0)

M.times do
  l, r = gets.split.map(&:to_i)
  l -= 1
  cards[l] += 1
  cards[r] -= 1
end

s = Array.new(N, 0)
s[0] = cards[0]
(1..N).each do |i|
  s[i] = s[i-1] + cards[i]
end
ans = 0
s.each do |x|
  ans += 1 if x == M
end
p ans