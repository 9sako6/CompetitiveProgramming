s = gets.chomp
a = Array.new(s.size + 1, 0)

n = s.size + 1
n.times do |i|
  if i != 0 && s[i - 1] == "<"
    a[i] = a[i - 1] + 1
  end
end
(n - 1).downto(0) do |i|
  if i != n - 1 && s[i] == ">"
    a[i] = [a[i + 1] + 1, a[i]].max
  end
end
p a.inject(&:+)
