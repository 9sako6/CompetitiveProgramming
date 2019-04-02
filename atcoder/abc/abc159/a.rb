n, m = gets.split.map(&:to_i)

def con(a)
  a * (a - 1) / 2
end

p con(n) + con(m)
