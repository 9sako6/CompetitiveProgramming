def min(x, y)
  return (x < y ? x : y)
end

N, Ma, Mb = gets.split.map(&:to_i)
a, b, c = [], [], []
N.times do
  tmp = gets.split.map(&:to_i)
  a << tmp[0]
  b << tmp[1]
  c << tmp[2]
end
INF = Float::INFINITY
MAX = 40 * 10 + 1
dp = Array.new(N + 1) { Array.new(MAX) { Array.new(MAX, INF) } }
dp[0][0][0] = 0
N.times do |i|
  MAX.times do |ca|
    MAX.times do |cb|
      next if dp[i][ca][cb] == INF
      dp[i + 1][ca][cb] = min(dp[i + 1][ca][cb], dp[i][ca][cb])
      dp[i + 1][ca + a[i]][cb + b[i]] = min(dp[i + 1][ca + a[i]][cb + b[i]], dp[i][ca][cb] + c[i])
    end
  end
end
ans = INF
(1...MAX).each do |ca|
  (1...MAX).each do |cb|
    if ca * Mb == cb * Ma
      ans = min(ans, dp[N][ca][cb])
    end
  end
end
p (ans == INF ? -1 : ans)
