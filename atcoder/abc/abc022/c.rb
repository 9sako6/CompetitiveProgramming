n, m = gets.split.map(&:to_i)
d = Array.new(n) { Array.new(n, Float::INFINITY) }
rin = []
n.times { |v| d[v][v] = 0 }
m.times do
  u, v, l = gets.split.map(&:to_i)
  u -= 1
  v -= 1
  if u == 0
    rin << [v, l]
  else
    d[u][v] = l
    d[v][u] = l
  end
end

n.times do |k|
  dk = d[k]
  n.times do |i|
    di = d[i]
    dik = di[k]
    (i + 1...n).each do |j|
      tmp = dik + dk[j]
      if tmp < di[j]
        di[j] = d[j][i] = tmp
      end
    end
  end
end
ans = Float::INFINITY
rin.combination(2) do |a, b|
  tmp = d[a[0]][b[0]] + a[1] + b[1]
  ans = tmp if ans > tmp
end

p ans == Float::INFINITY ? -1 : ans
