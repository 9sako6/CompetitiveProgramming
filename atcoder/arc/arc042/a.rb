n, m = gets.split.map(&:to_i)
a = []
m.times do
  a << gets.to_i
end

used = Array.new(n)
# hatsukakikodomo = Array.new(n)
ans = []
a.reverse.each do |ai|
  unless used[ai - 1]
    ans << ai
    used[ai - 1] = true
  end
end
n.times do |i|
  unless used[i]
    ans << i + 1
  end
end

puts ans
