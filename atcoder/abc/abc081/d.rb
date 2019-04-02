n = gets.to_i
a = gets.split.map(&:to_i)

def f(a, x, y)
  a[y] += a[x]
  puts [x + 1, y + 1] * " "
end

p n * 2
amax = a.max
amin = a.min
# p amax
# p amin
if amax.abs >= amin.abs
  prev = a.index(amax)
  n.times do |i|
    f(a, prev, i)
    # prev = i
    # p a
  end
  # p a
  prev = a.index(a.max)
  n.times do |i|
    f(a, prev, i)
    prev = i
  end
else
  prev = a.index(amin)
  (n - 1).downto(0) do |i|
    f(a, prev, i)
    # prev = i
  end
  prev = a.index(a.min)
  (n - 1).downto(0) do |i|
    f(a, prev, i)
    prev = i
  end
end

# p a
