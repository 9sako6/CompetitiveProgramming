s=gets.chomp
K=gets.to_i
subs = {}
(1..K).each do |k|
  (0..s.size-k).each do |i|
    subs[s[i...i+k]] = true
  end
end
puts subs.keys.sort[K-1]