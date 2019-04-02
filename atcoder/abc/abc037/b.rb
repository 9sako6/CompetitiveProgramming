n, q = gets.split.map(&:to_i)
a = Array.new(n, 0)
q.times do
  l, r, t = gets.split.map(&:to_i)
  l -= 1
  r -= 1
  a[l..r] = Array.new(r - l + 1, t)
end
puts a
