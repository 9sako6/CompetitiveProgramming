n, m = gets.split.map(&:to_i)
max = 1e10
d = Array.new(n) { Array.new(n, max) }
n.times { |i| d[i][i] = 0 }
m.times do
  a, b, c = gets.split.map(&:to_i)
  a -= 1
  b -= 1
  d[a][b] = c
  d[b][a] = c
end
n.times do |k|
  dk = d[k]
  n.times do |i|
    di = d[i]
    dik = di[k]
    n.times do |j|
      tmp = dik + dk[j]
      di[j] = tmp if tmp < di[j]
    end
  end
end

p (0...n).map { |i| d[i].max }.min
