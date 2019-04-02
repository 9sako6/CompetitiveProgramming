n = gets.to_i
a = gets.split.map(&:to_i)

m = Float::INFINITY
ans = 0
a.each_with_index do |ai, i|
  if ai < m
    m = ai
    ans += 1
  end
end
p ans