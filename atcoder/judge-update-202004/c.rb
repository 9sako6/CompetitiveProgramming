a, b, c = gets.split.map(&:to_i)
n = a + b + c
x = [a, b, c]
ans = 0
[*1..n].permutation.each do |d|
  e = [d[0...a], d[a...a + b], d[a + b...n]]
  ok = true
  3.times do |i|
    1.upto(x[i] - 1) do |j|
      ok = false if e[i][j] <= e[i][j - 1]
    end
  end
  b.times do |j|
    ok = false if e[1][j] <= e[0][j]
  end
  c.times do |j|
    ok = false if e[2][j] <= e[1][j]
  end
  ans += 1 if ok
end
p ans
