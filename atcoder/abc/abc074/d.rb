n = gets.to_i
d = n.times.map { gets.split.map(&:to_i) }
# d = a.map(&:dup)
a = Array.new(n) { Array.new(n, true) }
n.times do |k|
  dk = d[k]
  n.times do |i|
    di = d[i]
    dik = di[k]
    ai = a[i]
    next if i == k
    (i + 1...n).each do |j|
      next if i == j || j == k
      tmp = dik + dk[j]
      if (dij = di[j]) > tmp
        puts -1
        exit
      elsif tmp == dij
        ai[j] = a[j][i] = false
      end
    end
  end
end
ans = 0
n.times do |i|
  (i + 1...n).each do |j|
    ans += d[i][j] if a[i][j]
  end
end
p ans
